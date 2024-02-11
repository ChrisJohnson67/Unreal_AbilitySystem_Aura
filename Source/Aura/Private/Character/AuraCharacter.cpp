// Copyright Silversteel


#include "Character/AuraCharacter.h"
#include "AbilitySystemComponent.h"
#include "Player/AuraPlayerState.h"
#include "AttributeSet.h"
#include "Player/AuraPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UI/HUD/AuraHUD.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, CameraRotationRate, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//Init ability actor info on the client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	if (AuraPlayerState)
	{
		AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
		AttributeSet = AuraPlayerState->GetAttributeSet();
		if (AbilitySystemComponent)
			AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);

		UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent);
		if(AuraASC)
			AuraASC->AbilityActorInfoSet();

		AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController());
		if (AuraPlayerController)
		{
			AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD());
			if (AuraHUD)
			{
				AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			}
		}

		InitializeDefaultAttributes();
	}
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Init ability actor info on the server
	InitAbilityActorInfo();
}

int32 AAuraCharacter::GetPlayerLevel()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	if (AuraPlayerState)
	{
		return AuraPlayerState->GetPlayerLevel();
	}
}
