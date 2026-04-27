// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameCoreEnums.generated.h"

/**
 * 
 */

// 为了防止头文件循环，所以创建一个专门存放Enum的核心


UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	None UMETA(DisplayName = "无"),
	Summoner    UMETA(DisplayName="召唤"),
	Melee       UMETA(DisplayName="近战"),
	Ranged      UMETA(DisplayName="远程")
};

UENUM(BlueprintType)
enum class EHitReactType : uint8
{
	// 默认值
	None UMETA(DisplayName = "无"),
	// ===================== 基础方向受击 =====================
	Front UMETA(DisplayName = "正面受击"),
	Back UMETA(DisplayName = "背面受击"),
	Left UMETA(DisplayName = "左侧受击"),
	Right UMETA(DisplayName = "右侧受击"),
    
	// 斜向扩展受击
	FrontLeft UMETA(DisplayName = "左前受击"),
	FrontRight UMETA(DisplayName = "右前受击"),
	BackLeft UMETA(DisplayName = "左后受击"),
	BackRight UMETA(DisplayName = "右后受击"),

	// ===================== 特殊效果受击 =====================
	LaunchUp UMETA(DisplayName = "被打上天"),
	Stun UMETA(DisplayName = "眩晕"),
	Bind UMETA(DisplayName = "捆绑"),
};

UCLASS()
class CBJQ_API UGameCoreEnums : public UObject
{
	GENERATED_BODY()
};
