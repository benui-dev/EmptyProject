#include "Dog.generated.h"

UCLASS(Blueprintable, EditInlineNew, BlueprintType, DefaultToInstanced)
class UAnimal : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bIsCool;
};

UCLASS()
class UDog : public UAnimal
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Woof;
};

USTRUCT(BlueprintType)
struct FAnimalContainer
{
	GENERATED_BODY()
public:

	FAnimalContainer()
	{ }

	FAnimalContainer(UAnimal* InObject)
	: ObjectInstance(InObject)
	{ }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced)
	TObjectPtr<UAnimal> ObjectInstance = nullptr;

	FORCEINLINE bool operator==(const FAnimalContainer& Other) const { return ObjectInstance == Other.ObjectInstance; }
	FORCEINLINE bool operator!=(const FAnimalContainer& Other) const { return ObjectInstance != Other.ObjectInstance; }
	friend uint32 GetTypeHash(const FAnimalContainer& Container) { return GetTypeHash(Container.ObjectInstance); }

};

UCLASS(Blueprintable)
class UZoo : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FAnimalContainer AnimalContainer;

	UPROPERTY(EditAnywhere, Instanced)
	TObjectPtr<UAnimal> AnimalInstanced;
};
