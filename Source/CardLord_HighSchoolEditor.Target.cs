// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CardLord_HighSchoolEditorTarget : TargetRules
{
	public CardLord_HighSchoolEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "CardLord_HighSchool" } );
	}
}
