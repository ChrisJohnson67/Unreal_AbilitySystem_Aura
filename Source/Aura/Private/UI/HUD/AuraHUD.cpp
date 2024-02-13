// Copyright Silversteel


#include "UI/HUD/AuraHUD.h"
#include "UI/Widgets/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& Params)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(Params);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* AC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not initialized, fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not initialized, fill out BP_AuraHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	if (Widget)
	{
		OverlayWidget = Cast<UAuraUserWidget>(Widget);
		const FWidgetControllerParams Params(AC, PS, ASC, AS);
		UOverlayWidgetController* WidgetController = GetOverlayWidgetController(Params);

		OverlayWidget->SetWidgetController(WidgetController);
		WidgetController->BroadcastInitialValues();
		Widget->AddToViewport();
	}

}

void AAuraHUD::InitAttributeMenu(APlayerController* AC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(AttributeMenuWidgetClass, TEXT("AttributeMenuWidgetClass is not initialized, fill out BP_AuraHUD"));
	checkf(AttributeMenuWidgetControllerClass, TEXT("AttributeMenuWidgetControllerClass is not initialized, fill out BP_AuraHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), AttributeMenuWidgetClass);
	if (Widget)
	{
		AttributeMenuWidget = Cast<UAuraUserWidget>(Widget);
		const FWidgetControllerParams Params(AC, PS, ASC, AS);
		UOverlayWidgetController* WidgetController = GetOverlayWidgetController(Params);

		AttributeMenuWidget->SetWidgetController(WidgetController);
		WidgetController->BroadcastInitialValues();
		Widget->AddToViewport();
	}
}
