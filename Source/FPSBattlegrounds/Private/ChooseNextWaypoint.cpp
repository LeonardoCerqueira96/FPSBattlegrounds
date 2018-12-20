// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Getting necessary objects
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	UPatrollingComponent* PatrollingComponent = ControlledPawn->FindComponentByClass<UPatrollingComponent>();

	if (!PatrollingComponent) { return EBTNodeResult::Failed; }
	if (PatrollingComponent->GetWaypointsNum() == 0) { return EBTNodeResult::Succeeded; }

	// Setting next waypoint
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrollingComponent->GetWaypoint(Index));

	// Cycling index
	int32 WaypointsLength = PatrollingComponent->GetWaypointsNum();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % WaypointsLength);

	return EBTNodeResult::Succeeded;
}
