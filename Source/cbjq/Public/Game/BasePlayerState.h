// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/PlayerState.h"
#include "BasePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CBJQ_API ABasePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	// Question:3.1 构造函数的作用是什么?
	ABasePlayerState();

	// Question:3.1 ASC和AS分别用来做什么?
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	TObjectPtr<UAttributeSet> GetAttributeSet() const;
	
protected:
	// Question:3.1 为什么需要标记UPROPERTY?VisibleAnywhere是什么？还有其他的吗？
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributesSet;

	
};
