// Copyright Silversteel


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(FGameplayTag& GameplayTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformationList)
	{
		if (Info.AttributeTag == GameplayTag)
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("AttributeInfo for tag %s not found"), *GameplayTag.ToString());
	}
	return FAuraAttributeInfo();
}
