// Copyright Silversteel

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "EnemyInterface.h"
#include "Interaction/CombatInterface.h"
#include "AuraEnemy.generated.h"

/**
 *
 */
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
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Level = 1;
};
