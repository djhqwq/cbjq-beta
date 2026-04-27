// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "../../../../../../../epic engine/UE_5.2/Engine/Plugins/FX/Niagara/Source/Niagara/Classes/NiagaraSystem.h"
#include "Core/GameCoreEnums.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnASCRegistered, UAbilitySystemComponent*);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeathDynMultiDelegate, AActor*, DeadActor);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnDamageMultiDelegate, float);

USTRUCT(BlueprintType)
struct FTaggedMontage
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAnimMontage> Montage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag SocketTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USoundBase> ImpactSound = nullptr;
};
UINTERFACE(MinimalAPI)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CBJQ_API ICombatInterface
{
	GENERATED_BODY()

public:
	//Question:3.3.1 虚函数和纯虚函数的区别，他们的作用分别是什么？
	//Question:3.3.1 为什么要在接口里使用纯虚函数，如果使用它要注意些什么？
	//Question:3.3.1 指针和引用的区别是什么？
	virtual void Die(const FHitResult& DeathImpulse) = 0;
	//Question:3.3 动态多播和普通多播的区别，以及这两者的作用是什么？
	virtual FOnDeathDynMultiDelegate& GetOnDeathDynMultiDelegate() = 0;
	virtual FOnDamageMultiDelegate& GetOnDamageMultiDelegate() = 0;
	virtual FOnASCRegistered& GetOnASCRegisteredDelegate() = 0;

	virtual bool IsHeroCharacter() const;

	//Question:3.3 BlueprintNativeEvent和BlueprintCallable在这个接口里起到社么作用？
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	ACharacter* GetCharacter();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetCombatSocketLocation(const FGameplayTag& NewSocketTag);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetCombatSocketLocationByName(const FName& NewSocketName);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	USkeletalMeshComponent* GetSkeletalMeshComponent();
	
	virtual FHitResult& GetCursorHitResult();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateFacingTarget(FVector NewSourceActor, FVector NewTargetActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UAnimMontage* GetHitReactMontage();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsDead();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	AActor* GetAvatar();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<FTaggedMontage> GetAttackMontage();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UNiagaraSystem* GetBloodEffect();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FTaggedMontage GetTaggedMontageByTag(const FGameplayTag& NewMontageTag);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetMinionCount();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void IncrementMiniCount(int Amount);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	ECharacterClass GetCharacterClass();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetInShockLoop(bool bInLoop);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	AActor* GetWeapon();

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetWeapon(AActorWeapon* NewWeapon);*/

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsBeingShocked() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetIsBeingShocked(bool bInShock);

	virtual bool GetIsStunded();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	EHitReactType GetHitReactType();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool SetEHitReactType(EHitReactType NewHitReactType);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsLaunchUpHit();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetIsLaunchUpHit(bool bInIsLaunchUpHit);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsStunHit();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetIsStunHit(bool bInIsStunHit);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool IsBindHit();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetIsBindHit(bool bInIsBindHit);

private:
	EHitReactType HitReactType = EHitReactType::None;

	bool bIsLaunchUpHit = false;

	bool bIsStunHit = false;

	bool bIsBindHit = false;
};
