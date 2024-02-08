// Copyright Silversteel


#include "UI/Widgets/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* Controller)
{
	WidgetController = Controller;
	WidgetControllerSet();
}
