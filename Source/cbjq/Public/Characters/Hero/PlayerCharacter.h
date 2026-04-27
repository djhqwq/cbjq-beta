// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CBJQ_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FirstPerson")
	TObjectPtr<USpringArmComponent> FirstSpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FirstPerson")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TObjectPtr<USkeletalMeshComponent> FaceSkeletalMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	TObjectPtr<USkeletalMeshComponent> SkeletalMesh_Outline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	TObjectPtr<USkeletalMeshComponent> FaceSkeletalMesh_Outline;

private:
	float BaseWalkSpeed = 250.f;
	
};
