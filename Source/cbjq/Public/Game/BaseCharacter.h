// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Ability/BaseAbilitySystemComponent.h"
#include "Attribute/BaseAttributeSet.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "BaseCharacter.generated.h"

class ABasePlayerController;
enum class EHitReactType : uint8;

UCLASS()
class CBJQ_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()
private:
	EHitReactType HitReactType;
public:
	ABaseCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	TObjectPtr<UAttributeSet> GetAttributeSet() const { return AttributeSet;}

	//接口

	//end

	
protected:
	virtual void BeginPlay() override;

public:
	//Question: 3.2 BlueprintReadWrite有什么作用？还有其他的吗？
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ThirdPerson")
	TObjectPtr<USpringArmComponent> ThirdSpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ThirdPerson")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;
	
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// GAS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBaseAbilitySystemComponent> BaseAbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBaseAttributeSet> BaseAttributeSet;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ABasePlayerController> BasePlayerController;
};
