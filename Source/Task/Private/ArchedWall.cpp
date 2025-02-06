#include "ArchedWall.h"

DEFINE_LOG_CATEGORY(LogTask);


AArchedWall::AArchedWall()
{
 
	PrimaryActorTick.bCanEverTick = true;

	// Scene Component를 생성하고 루트로 설정
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// Static Mesh Component를 생성하고 Scene Component에 Attach
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// Static Mesh를 코드에서 설정
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Wall_Door_400x300.Wall_Door_400x300"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	PrimaryActorTick.bAllowTickBatching = true;	
}

void AArchedWall::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTask, Error, TEXT("START"));

	StartLocationY = GetActorLocation().Y;
}

void AArchedWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeedX))
	{
		AddActorWorldOffset(FVector(MoveSpeedX * DeltaTime, 0.0f, 0.0f));
	}

	if (!FMath::IsNearlyZero(MoveSpeedY))
	{
		float NewLocationY = StartLocationY + FMath::Sin(GetWorld()->GetTimeSeconds() * MoveSpeedY) * MoveRange;
		FVector NewLocation = GetActorLocation();
		NewLocation.Y = NewLocationY;
		SetActorLocation(NewLocation);
	}

	

	

}




