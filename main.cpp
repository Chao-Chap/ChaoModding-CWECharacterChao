#include "pch.h"
#include "cwe_api.h"
#include "ModelInfo.h"
#include "IniFile.hpp"
extern "C"
{
	//registering data functions. - Needs to exist.
	void (*RegisterDataFunc)(void* ptr);

	//Define Models
	ModelInfo* MDLCorrinChao; bool enablecorrin;
	ModelInfo* MDLodinChao; bool enableodin;
	ModelInfo* MDLtikalChao; bool enabletikal;
	ModelInfo* MDLRougeChao; bool enablerouge;
	ModelInfo* MDLEggmanChao; bool enableeggman;
	ModelInfo* MDLKlonoaChao; bool enablewahoo;
	ModelInfo* MDLViChao; bool enablevi;
	ModelInfo* MDLLombaxChao; bool enablelombax;
	ModelInfo* MDLbigChao; bool enablebig;
	ModelInfo* MDLtripChao; bool enabletrip;
	ModelInfo* MDLemerlChao; bool enableemerl;




	//NJS Type texture name and texture list. As is for old documentation.
	NJS_TEXNAME Biggear[40];
	NJS_TEXLIST biggear_texlist = { arrayptrandlength(Biggear) };
	NJS_TEXNAME tripgear[5];
	NJS_TEXLIST tripgear_texlist = { arrayptrandlength(tripgear) };

	//NJS Type texture name and texture list. As is for old documentation.
	NJS_TEXNAME tikal[15];
	NJS_TEXLIST tikal_texlist = { arrayptrandlength(tikal) };
	

	//Define models
	ModelInfo* MDLbigAccessory;
	ModelInfo* MDLtripAccessory;
	ModelInfo* MDLtripAccessory2;
	ModelInfo* MDLtikalAccessory;

	//create a UID for your accessory
	int bigAccessoryID;
	int triphatchaoAccessoryID;
	int triparmorAccessoryID;
	int tikalAccessoryID;
	//Black Market Item Attributes
	BlackMarketItemAttributes BMbigAccessory = { 1000, 500, 0, -1, -1, 0 };
	BlackMarketItemAttributes BMtripAccessory = { 500, 200, 0, -1, -1, 0 };
	BlackMarketItemAttributes BMtripAccessory2 = { 500, 200, 0, -1, -1, 0 };
	BlackMarketItemAttributes BMtikalAccessory2 = { 2000, 1000, 0, -1, -1, 0 };
	//Define a pointer function for pEvolveFunc
	//Define a pointer function for pEvolveFunc
	static bool CorrinEvolve(ObjectMaster* tp)
	{
		if (tp->Data1.Chao->ChaoDataBase_ptr->Alignment > -0.20 && tp->Data1.Chao->ChaoDataBase_ptr->Alignment < 0.20 && tp->Data1.Chao->ChaoDataBase_ptr->Happiness > 80 && tp->Data1.Chao->ChaoDataBase_ptr->Garden == ChaoArea_HeroGarden)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool OdinEvolve(ObjectMaster* tp)
	{
		if (tp->Data1.Chao->ChaoDataBase_ptr->Alignment < -0.60 && tp->Data1.Chao->ChaoDataBase_ptr->Garden == ChaoArea_DarkGarden && tp->Data1.Chao->ChaoDataBase_ptr->Medal == ChaoMedal_Dark)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool TikalEvolve(ObjectMaster* tp)
	{
		if (tp->Data1.Chao->ChaoDataBase_ptr->Alignment > 0.70 && tp->Data1.Chao->ChaoDataBase_ptr->SA2BCharacterBonds[4].a > 70 && strcmp(tp->Data1.Chao->ChaoDataBase_ptr->Name, "\x34\x49\x4B\x41\x4C") == 0)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}

	static bool RougeEvolve(ObjectMaster* tp)
	{
		if (tp->Data1.Chao->ChaoDataBase_ptr->StatLevels[(int)eCHAO_STATS::Fly] > 10 && tp->Data1.Chao->ChaoDataBase_ptr->SA2BCharacterBonds[5].a > 70 && tp->Data1.Chao->ChaoDataBase_ptr->HideFeet == true)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}

	static bool EggmanEvolve(ObjectMaster* tp)
	{
		if (tp->Data1.Chao->ChaoDataBase_ptr->StatLevels[(int)eCHAO_STATS::Pwr] > 15 && tp->Data1.Chao->ChaoDataBase_ptr->SA2BCharacterBonds[3].a > 70)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool KlonoaEvolve(ObjectMaster* tp)
	{
		if (strcmp(tp->Data1.Chao->ChaoDataBase_ptr->Name, "\x37\x41\x48\x4F\x4F") == 0)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}

	static bool ViEvolve(ObjectMaster* tp)
	{
		if (strcmp(tp->Data1.Chao->ChaoDataBase_ptr->Name, "\x23\x55\x54\x49\x45\x0D\x22") == 0)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool LombaxEvolve(ObjectMaster* tp)
	{
		if (tp->Data1.Chao->ChaoDataBase_ptr->Headgear = 12 && tp->Data1.Chao->ChaoDataBase_ptr->Medal == ChaoMedal_Challenge)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool BigEvolve(ObjectMaster* tp)
	{
		if (strcmp(tp->Data1.Chao->ChaoDataBase_ptr->Name, "\x22\x49\x47\x5F\x27\x55\x59") == 0)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool TripEvolve(ObjectMaster* tp)
	{
		if (strcmp(tp->Data1.Chao->ChaoDataBase_ptr->Name, "\x34\x52\x49\x50") == 0)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	static bool EmerlEvolve(ObjectMaster* tp)
	{
		if (strcmp(tp->Data1.Chao->ChaoDataBase_ptr->Name, "\x27\x49\x5A\x4F\x49\x44") == 0)
		{
			PrintDebug("Chao evolving");
			return true;
		}
		else
			return false;
	}
	//main CWE Load function -- Important stuff like adding your CWE mod goes here
	void CWELoad(CWE_REGAPI* cwe_api, ObjectMaster* tp)
	{

		//Define Character Chao data:
		CWE_API_CHAO_DATA CharChao_pData;
		if (enablecorrin)
		{
			CharChao_pData =
			{
				MDLCorrinChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"CorrinChao",			//TextureName
				7,				//TextureCount
				0xFF8CB2B3,			//IconColor - hex, 6 bytes
				ICON_TYPE_HALO,			//IconType
				NULL,				//pIconData

				CorrinEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Corrin Chao",			//Name
				"cwe_corrin",			//id

			};

			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enableodin)
		{
			//Define Character Chao data:
			CharChao_pData =


			{
				MDLodinChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"OdinChao",			//TextureName
				7,				//TextureCount
				0xFF8300FF,			//IconColor - hex, 6 bytes
				ICON_TYPE_SPIKY,			//IconType
				NULL,				//pIconData

				OdinEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Odin Chao",			//Name
				"cwe_odin",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enabletikal)
		{
			CharChao_pData =


			{
				MDLtikalChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"TikalChao",			//TextureName
				4,				//TextureCount
				0xFFFF0000,			//IconColor - hex, 6 bytes
				ICON_TYPE_BALL,			//IconType
				NULL,				//pIconData

				TikalEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Tikal Chao",			//Name
				"cwe_tikal",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enablerouge)
		{
			CharChao_pData =


			{
				MDLRougeChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"RougeChao",			//TextureName
				6,				//TextureCount
				0xFF8300FF,			//IconColor - hex, 6 bytes
				ICON_TYPE_SPIKY,			//IconType
				NULL,				//pIconData

				RougeEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Rouge Chao",			//Name
				"cwe_rouge",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enableeggman)
		{
			CharChao_pData =


			{
				MDLEggmanChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"EggmanChao",			//TextureName
				6,				//TextureCount
				0xFFFAFF00,			//IconColor - hex, 6 bytes
				ICON_TYPE_SPIKY,			//IconType
				NULL,				//pIconData

				EggmanEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Eggman Chao",			//Name
				"cwe_Eggman",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enablewahoo)
		{
			CharChao_pData =


			{
				MDLKlonoaChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"KlonoaChao",			//TextureName
				6,				//TextureCount
				0xFF00FAFF,			//IconColor - hex, 6 bytes
				ICON_TYPE_BALL,			//IconType
				NULL,				//pIconData

				KlonoaEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Klonoa Chao",			//Name
				"cwe_Klonoa",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enablevi)
		{
			CharChao_pData =


			{
				MDLViChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"ViChao",			//TextureName
				6,				//TextureCount
				0xFF404040,			//IconColor - hex, 6 bytes
				ICON_TYPE_BALL,			//IconType
				NULL,				//pIconData

				ViEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Vi Chao",			//Name
				"cwe_vi",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enablelombax)
		{
			CharChao_pData =


			{
				MDLLombaxChao->getmodel(),	//pobject
				{0},				//pSecondEvoList[5]

				"LombaxChao",			//TextureName
				6,				//TextureCount
				0xFF404040,			//IconColor - hex, 6 bytes
				ICON_TYPE_BALL,			//IconType
				NULL,				//pIconData

				LombaxEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Lombax Chao",			//Name
				"cwe_lombax",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enableemerl)
		{
			CharChao_pData =


			{
				MDLemerlChao->getmodel(),	//pobject
				{0},				//pSecondEvoList[5]

				"emerlChao",			//TextureName
				6,				//TextureCount
				0xFF404040,			//IconColor - hex, 6 bytes
				ICON_TYPE_HALO,			//IconType
				NULL,				//pIconData

				EmerlEvolve,			//pEvolveFunc - TO FIX

				0,				//Flags
				"Emerl Chao",			//Name
				"cwe_Gizoid",			//id
			};


			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		}
		if (enablebig)
		{
			CharChao_pData =
			{
				MDLbigChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"BigChao",			//TextureName
				7,				//TextureCount
				0xFFFAFF00,			//IconColor - hex, 6 bytes
				ICON_TYPE_BALL,			//IconType
				NULL,				//pIconData

				BigEvolve,			//pEvolveFunc 

				0,				//Flags
				"Big The Cat Chao",			//Name
				"cwe_big",			//id

			};
			//add the Chao Type
			cwe_api->AddChaoType(&CharChao_pData);
		
		}
		if (enabletrip)
		{
			CharChao_pData =
			{
				MDLtripChao->getmodel(),	//pObject
				{0},				//pSecondEvoList[5]

				"tripChao",			//TextureName
				7,				//TextureCount
				0xFFFAFF00,			//IconColor - hex, 6 bytes
				ICON_TYPE_BALL,			//IconType
				NULL,				//pIconData

				TripEvolve,			//pEvolveFunc 

				0,				//Flags
				"Trip Chao",			//Name
				"cwe_trip",			//id
			};
			cwe_api->AddChaoType(&CharChao_pData);
		}
		//register your textures here (by filename.pak)
		cwe_api->RegisterChaoTexlistLoad("BIGGEAR", &biggear_texlist);

		//register your accessory here
		bigAccessoryID = cwe_api->RegisterChaoAccessory(Generic1, MDLbigAccessory->getmodel(), &biggear_texlist, &BMbigAccessory, "Big's Fishing Gear", "For catching fish, and also frogs!");
		//register your textures here (by filename.pak)
		cwe_api->RegisterChaoTexlistLoad("Triphat", &tripgear_texlist);

	

		//register your accessory here
		triphatchaoAccessoryID = cwe_api->RegisterChaoAccessory(Head, MDLtripAccessory->getmodel(), &tripgear_texlist, &BMtripAccessory, "Trip Helmet", "Wear to avoid spoilers!");
		//register your accessory here
		triparmorAccessoryID = cwe_api->RegisterChaoAccessory(Generic1, MDLtripAccessory2->getmodel(), &tripgear_texlist, &BMtripAccessory2, "Trip Armor", "Wear to avoid spoilers!");
		tikalAccessoryID = cwe_api->RegisterChaoAccessory(Generic1, MDLtikalAccessory->getmodel(), &tikal_texlist, &BMtikalAccessory2, "Tikal Jewlery", "Tikal crafted it lovingly for her chao.");
		//register your textures here (by filename.pak)
		cwe_api->RegisterChaoTexlistLoad("tiara", &tikal_texlist);
	}
	//initialization function - MUST exist in order to have CWE and SA2 see your mod
	__declspec(dllexport) void Init(const char* path)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

	 enablecorrin = config->getBool("", "Corrin Chao", true);
	 enableodin = config->getBool("", "Odin Chao", true);
	 enablevi = config->getBool("", "Vi Chao", true);
	 enablewahoo = config->getBool("", "Klonoa Chao", true);
	 enabletikal = config->getBool("", "Tikal Chao", true);
	 enableeggman = config->getBool("", "Eggman Chao", true);
	 enablerouge = config->getBool("", "Rouge Chao", true);
	 enablelombax = config->getBool("", "Lombax Chao", true);
	 enablebig = config->getBool("", "Big the Cat Chao", true);
	 enabletrip = config->getBool("", "Trip Chao", true);
	 enableemerl = config->getBool("", "Emerl Chao", true);
		delete config;
		HMODULE h = GetModuleHandle(L"CWE");

		std::string pathStr = std::string(path) + "\\";

		MDLCorrinChao = new ModelInfo(pathStr + "MDLCorrinChao.sa2mdl");
		MDLodinChao = new ModelInfo(pathStr + "MDLOdinChao.sa2mdl");
		MDLtikalChao = new ModelInfo(pathStr + "MDLTikalChao.sa2mdl");
		MDLRougeChao = new ModelInfo(pathStr + "MDLRougeChao.sa2mdl");
		MDLKlonoaChao = new ModelInfo(pathStr + "MDLKlonoaChao.sa2mdl");
		MDLEggmanChao = new ModelInfo(pathStr + "MDLEggmanChao.sa2mdl");
		MDLViChao = new ModelInfo(pathStr + "MDLvichao.sa2mdl");
		MDLLombaxChao = new ModelInfo(pathStr + "MDLLombaxchao.sa2mdl");
		MDLbigChao = new ModelInfo(pathStr + "MDLBigChao.sa2mdl");
		MDLtripChao = new ModelInfo(pathStr + "MDLTripChao.sa2mdl");
		MDLemerlChao = new ModelInfo(pathStr + "MDLEmerlChao.sa2mdl");
		RegisterDataFunc = (void (*)(void* ptr))GetProcAddress(h, "RegisterDataFunc");

		MDLbigAccessory = new ModelInfo(pathStr + "Biggear.sa2mdl");
		MDLtripAccessory = new ModelInfo(pathStr + "triphat.sa2mdl");
		MDLtripAccessory2 = new ModelInfo(pathStr + "triparmor.sa2mdl");
		MDLtikalAccessory = new ModelInfo(pathStr + "TIARA.sa2mdl");

		RegisterDataFunc(CWELoad);
	}
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}
