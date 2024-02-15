// Copyright Silversteel

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "EnemyInterface.h"
#include "Interaction/CombatInterface.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;



UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/* End Combat Interface */

protected:

	virtual void BeginPlay() override;
	void BindHealthBarDelegates();
	virtual void InitAbilityActorInfo() override;
	void ShowHealthBar(bool bShow);
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ECharacterClass CharacterClass = ECharacterClass::Elementalist;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TObjectPtr<UWidgetComponent> HealthBarWidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Level = 1;
};
