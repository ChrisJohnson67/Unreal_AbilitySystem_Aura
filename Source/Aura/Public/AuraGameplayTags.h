// Copyright Silversteel

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *
 */
struct FAuraGameplayTags
{
public:

	static const FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;

	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPen;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CritHitChance;
	FGameplayTag Attributes_Secondary_CritHitDamage;
	FGameplayTag Attributes_Secondary_CritHitResist;
	FGameplayTag Attributes_Secondary_HealthRegen;
	FGameplayTag Attributes_Secondary_ManaRegen;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;

protected:

private:

	static FAuraGameplayTags GameplayTags;
};
