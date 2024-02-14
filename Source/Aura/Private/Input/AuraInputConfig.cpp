// Copyright Silversteel


#include "Input/AuraInputConfig.h"
#include "InputAction.h"
#include "GameplayTagContainer.h"

const UInputAction* UAuraInputConfig::GetInputAction(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const auto& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("InputAction not found for tag %s"), *InputTag.ToString());
	}
	return nullptr;
}
