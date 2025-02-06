#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArchedWall.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogTask, Warning, All);

UCLASS()
class TASK_API AArchedWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArchedWall();

protected:
	
	// 루트 컴포넌트 나타내는 Scene Component 포인터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ArchedWall|Components")
	USceneComponent* SceneRoot;
	// Static Mesh Component 포인터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ArchedWall|Components")
	UStaticMeshComponent* StaticMeshComp;

	//전방이동 인스턴스로 바꾸기
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "ArchedWall|Properties")
	float MoveSpeedX;
	
	//좌우 이동
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "ArchedWall|Properties")
	float MoveRange;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "ArchedWall|Properties")
	float MoveSpeedY;

	float StartLocationY;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
