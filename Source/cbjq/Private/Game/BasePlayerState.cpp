// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BasePlayerState.h"

#include "Ability/BaseAbilitySystemComponent.h"
#include "Attribute/BaseAttributeSet.h"

ABasePlayerState::ABasePlayerState()
{
	//Question:3.3.1 为什么要CreateDefaultSubobject
	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("BaseAbilitySystemComponent"));

	//Question:3.3.1 SetIsReplicated是什么？
	AbilitySystemComponent->SetIsReplicated(true);
	
	//Question:3.3.1 Minimal,Mixed是什么,还有哪些？
	//TODO:最好用AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributesSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("BaseAttributeSet"));

	//Question:3.3.1 下面这三个是什么，有什么作用？
	bReplicates = true;
	NetUpdateFrequency = 100.0f;
	bAlwaysRelevant = true;
}


UAbilitySystemComponent* ABasePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

TObjectPtr<UAttributeSet> ABasePlayerState::GetAttributeSet() const
{
	return AttributesSet;
}
