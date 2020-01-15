// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class CardLord_HighSchoolTarget : TargetRules
{
	public CardLord_HighSchoolTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "CardLord_HighSchool" } );
	}
}
