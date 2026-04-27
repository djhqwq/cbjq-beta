// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Hero/PlayerCharacter.h"

#include "cbjq/cbjq.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 第三人称
	ThirdSpringArmComponent->SetupAttachment(GetMesh());
	ThirdSpringArmComponent->TargetArmLength = 300.f;
	ThirdSpringArmComponent->SocketOffset = FVector(0, 30.f, 0);
	ThirdSpringArmComponent->SetRelativeRotation(FRotator(0, 0, 70));
	ThirdSpringArmComponent->bUsePawnControlRotation = true;
	//Question:3.2 下面这两个有什么作用？
	ThirdSpringArmComponent->bEnableCameraLag = true;
	ThirdSpringArmComponent->bEnableCameraRotationLag = true;

	// 第一人称
	FirstSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("FirstSpringArmComponent");
	FirstSpringArmComponent->SetupAttachment(GetMesh(), "Bip001-Head");
	FirstSpringArmComponent->TargetArmLength = 0.f;
	FirstSpringArmComponent->bUsePawnControlRotation = true;
	FirstSpringArmComponent->bEnableCameraLag = true;
	FirstSpringArmComponent->bEnableCameraRotationLag = true;
	
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCamera->SetupAttachment(FirstSpringArmComponent);

	// 胶囊体
	GetCapsuleComponent()->InitCapsuleSize(34.f, 88.f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_ExcludePlayers, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Interact, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);

	// 网格体
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -85.f));
	GetMesh()->SetRelativeRotation(FRotator(0, 0, -90.f));
	GetMesh()->SetCollisionProfileName(UCollisionProfile::CustomCollisionProfileName);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetCollisionResponseToChannel(ECC_ExcludePlayers, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Interact, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECR_Block);

	// 面部网格体
	FaceSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("FaceSkeletalMesh");
	FaceSkeletalMesh->SetupAttachment(GetMesh(), "BipOO1-HeadSocket");
	FaceSkeletalMesh->SetRenderCustomDepth(true);
	FaceSkeletalMesh->SetRelativeLocation(FVector(0, 0, -85.f));
	FaceSkeletalMesh->SetRelativeRotation(FRotator(0, 0, -90.f));
	FaceSkeletalMesh->SetCollisionProfileName(UCollisionProfile::CustomCollisionProfileName);
	FaceSkeletalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FaceSkeletalMesh->SetCollisionResponseToChannel(ECC_ExcludePlayers, ECR_Ignore);
	FaceSkeletalMesh->SetCollisionResponseToChannel(ECC_Interact, ECR_Ignore);
	FaceSkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECR_Block);

	// 角色移动组件
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	Tags.Add(FName("Player"));

	SkeletalMesh_Outline = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh_Outline");
	SkeletalMesh_Outline->SetupAttachment(GetMesh());
	FaceSkeletalMesh_Outline = CreateDefaultSubobject<USkeletalMeshComponent>("FaceSkeletalMesh_Outline");
	FaceSkeletalMesh_Outline->SetupAttachment(GetMesh(), "BipOO1-HeadSocket");
	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}
