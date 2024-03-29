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
class UBehaviorTree;
class AAuraAIController;


UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy();

	virtual void PossessedBy(AController* NewController) override;

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	virtual void Die() override;
	void SetCombatTarget_Implementation(AActor* InCombatTarget);
	AActor* GetCombatTarget_Implementation() const;
	/* End Combat Interface */

	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
	bool IsHitReacting() const { return bHitReacting; }

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintReadWrite, Category = "Combat")
	TObjectPtr<AActor> CombatTarget;

protected:

	virtual void BeginPlay() override;
	void BindHealthBarDelegates();
	virtual void InitAbilityActorInfo() override;
	void ShowHealthBar(bool bShow);
	virtual void InitializeDefaultAttributes() const override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	ECharacterClass CharacterClass = ECharacterClass::Elementalist;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TObjectPtr<UWidgetComponent> HealthBarWidgetComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Level = 1;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float BaseWalkSpeed = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float LifeSpan = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<AAuraAIController> AuraAIController;
};
