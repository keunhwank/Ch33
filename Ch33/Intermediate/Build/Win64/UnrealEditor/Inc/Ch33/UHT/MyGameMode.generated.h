// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CH33_MyGameMode_generated_h
#error "MyGameMode.generated.h already included, missing '#pragma once' in MyGameMode.h"
#endif
#define CH33_MyGameMode_generated_h

#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyGameMode(); \
	friend struct Z_Construct_UClass_AMyGameMode_Statics; \
public: \
	DECLARE_CLASS(AMyGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Ch33"), NO_API) \
	DECLARE_SERIALIZER(AMyGameMode)


#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyGameMode(AMyGameMode&&); \
	AMyGameMode(const AMyGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyGameMode) \
	NO_API virtual ~AMyGameMode();


#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h_10_PROLOG
#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h_13_INCLASS_NO_PURE_DECLS \
	FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CH33_API UClass* StaticClass<class AMyGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MyGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
