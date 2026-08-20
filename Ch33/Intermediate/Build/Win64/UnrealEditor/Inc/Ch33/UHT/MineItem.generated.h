// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MineItem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CH33_MineItem_generated_h
#error "MineItem.generated.h already included, missing '#pragma once' in MineItem.h"
#endif
#define CH33_MineItem_generated_h

#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMineItem(); \
	friend struct Z_Construct_UClass_AMineItem_Statics; \
public: \
	DECLARE_CLASS(AMineItem, ABaseItem, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Ch33"), NO_API) \
	DECLARE_SERIALIZER(AMineItem)


#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMineItem(AMineItem&&); \
	AMineItem(const AMineItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMineItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMineItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMineItem) \
	NO_API virtual ~AMineItem();


#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h_7_PROLOG
#define FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h_10_INCLASS_NO_PURE_DECLS \
	FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CH33_API UClass* StaticClass<class AMineItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE5_Git_Ch33_Ch33_Source_Ch33_Public_MineItem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
