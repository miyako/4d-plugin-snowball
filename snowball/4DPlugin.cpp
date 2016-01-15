/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : Snowball
 #	author : miyako
 #	2016/01/15
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

void PluginMain(PA_long32 selector, PA_PluginParameters params)
{
	try
	{
		PA_long32 pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		CommandDispatcher(pProcNum, pResult, pParams); 
	}
	catch(...)
	{

	}
}

void CommandDispatcher (PA_long32 pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
// --- Snowball

		case 1 :
			Snowball(pResult, pParams);
			break;

	}
}

// ----------------------------------- Snowball -----------------------------------

std::vector<std::string> split(const std::string &str){
  std::istringstream iss(str); std::vector<std::string> res;
  copy(std::istream_iterator<std::string>(iss),  std::istream_iterator<std::string>(), back_inserter(res));
  return res;
}
//http://shnya.jp/blog/?p=195

void Snowball(sLONG_PTR *pResult, PackagePtr pParams)
{
				C_TEXT Param1;
				ARRAY_TEXT Param2;
				ARRAY_TEXT Param3;
				C_LONGINT Param4;

				Param1.fromParamAtIndex(pParams, 1);
				Param4.fromParamAtIndex(pParams, 4);

				CUTF8String t;
				Param1.copyUTF8String(&t);
				std::string str((const char *)t.c_str());
				std::vector<std::string>words = split(str);

				struct sb_stemmer *stemmer;
				char *language = (char *)"english";

				Snowball_Language lang = (Snowball_Language)Param4.getIntValue();

				switch (lang) {
						case Snowball_Danish:
								language = (char *)"danish";
								break;
						case Snowball_Dutch:
								language = (char *)"dutch";
								break;
						case Snowball_English:
								language = (char *)"english";
								break;
						case Snowball_Finnish:
								language = (char *)"finnish";
								break;
						case Snowball_French:
								language = (char *)"french";
								break;
						case Snowball_German:
								language = (char *)"german";
								break;
						case Snowball_Hungarian:
								language = (char *)"hungarian";
								break;
						case Snowball_Italian:
								language = (char *)"italian";
								break;
						case Snowball_Norwegian:
								language = (char *)"norwegian";
								break;
						case Snowball_Portuguese:
								language = (char *)"portuguese";
								break;
						case Snowball_Romanian:
								language = (char *)"romanian";
								break;
						case Snowball_Russian:
								language = (char *)"russian";
								break;
						case Snowball_Spanish:
								language = (char *)"spanish";
								break;
						case Snowball_Swedish:
								language = (char *)"swedish";
								break;
						case Snowball_Turkish:
								language = (char *)"turkish";
								break;
						default:
								break;
				}

				char *charenc = NULL;//UTF-8

				stemmer = sb_stemmer_new(language, charenc);

				if (stemmer)
				{
								Param2.setSize(1);
								Param3.setSize(1);

								for(std::vector<std::string>::iterator it = words.begin(); it != words.end(); ++it) {
												std::string word = *it;
												sb_symbol * symbol = (sb_symbol *)word.c_str();
												int size = word.length();
												const sb_symbol *stemmed = sb_stemmer_stem(stemmer, symbol, size);
												if (stemmed)
												{
																CUTF8String w((const uint8_t *)symbol);
																CUTF8String s((const uint8_t *)stemmed);
																Param2.appendUTF8String(&w);
																Param3.appendUTF8String(&s);
												}
								}
								
								sb_stemmer_delete(stemmer);
				}

					Param2.toParamAtIndex(pParams, 2);
					Param3.toParamAtIndex(pParams, 3);
}
