// Copyright Silversteel

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 *
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:

	AAuraCharacter();
	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/* End Combat Interface */

protected:

	UPROPERTY(EditAnywhere)
	float CameraRotationRate = 540.0f;

private:
	virtual void InitAbilityActorInfo() override;
};
