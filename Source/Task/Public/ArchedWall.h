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
	
	// ��Ʈ ������Ʈ ��Ÿ���� Scene Component ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ArchedWall|Components")
	USceneComponent* SceneRoot;
	// Static Mesh Component ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ArchedWall|Components")
	UStaticMeshComponent* StaticMeshComp;

	//�����̵� �ν��Ͻ��� �ٲٱ�
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "ArchedWall|Properties")
	float MoveSpeedX;
	
	//�¿� �̵�
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "ArchedWall|Properties")
	float MoveRange;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "ArchedWall|Properties")
	float MoveSpeedY;

	float StartLocationY;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
