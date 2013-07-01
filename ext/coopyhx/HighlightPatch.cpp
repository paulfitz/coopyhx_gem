#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_CompareTable
#include <coopy/CompareTable.h>
#endif
#ifndef INCLUDED_coopy_CrossMatch
#include <coopy/CrossMatch.h>
#endif
#ifndef INCLUDED_coopy_Csv
#include <coopy/Csv.h>
#endif
#ifndef INCLUDED_coopy_HighlightPatch
#include <coopy/HighlightPatch.h>
#endif
#ifndef INCLUDED_coopy_HighlightPatchUnit
#include <coopy/HighlightPatchUnit.h>
#endif
#ifndef INCLUDED_coopy_IndexItem
#include <coopy/IndexItem.h>
#endif
#ifndef INCLUDED_coopy_IndexPair
#include <coopy/IndexPair.h>
#endif
#ifndef INCLUDED_coopy_Row
#include <coopy/Row.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_TableComparisonState
#include <coopy/TableComparisonState.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace coopy{

Void HighlightPatch_obj::__construct(::coopy::Table source,::coopy::Table patch)
{
HX_STACK_PUSH("HighlightPatch::new","coopy/HighlightPatch.hx",30);
{
	HX_STACK_LINE(31)
	this->source = source;
	HX_STACK_LINE(32)
	this->patch = patch;
	HX_STACK_LINE(33)
	this->header = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(34)
	this->headerPre = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(35)
	this->headerPost = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(36)
	this->headerRename = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(37)
	this->modifier = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(38)
	this->sourceInPatch = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(39)
	this->patchInSource = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(40)
	this->mods = Array_obj< ::coopy::HighlightPatchUnit >::__new();
	HX_STACK_LINE(41)
	this->cmods = Array_obj< ::coopy::HighlightPatchUnit >::__new();
	HX_STACK_LINE(42)
	this->haveSourceColumns = false;
	HX_STACK_LINE(43)
	this->actCache = HX_CSTRING("");
	HX_STACK_LINE(44)
	this->actBaseCache = HX_CSTRING("");
	HX_STACK_LINE(45)
	this->actIsUpdate = false;
	HX_STACK_LINE(46)
	this->actIsConflicted = false;
	HX_STACK_LINE(47)
	this->csv = ::coopy::Csv_obj::__new();
}
;
	return null();
}

HighlightPatch_obj::~HighlightPatch_obj() { }

Dynamic HighlightPatch_obj::__CreateEmpty() { return  new HighlightPatch_obj; }
hx::ObjectPtr< HighlightPatch_obj > HighlightPatch_obj::__new(::coopy::Table source,::coopy::Table patch)
{  hx::ObjectPtr< HighlightPatch_obj > result = new HighlightPatch_obj();
	result->__construct(source,patch);
	return result;}

Dynamic HighlightPatch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HighlightPatch_obj > result = new HighlightPatch_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

hx::Object *HighlightPatch_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::coopy::Row_obj)) return operator ::coopy::Row_obj *();
	return super::__ToInterface(inType);
}

Void HighlightPatch_obj::finishColumns( ){
{
		HX_STACK_PUSH("HighlightPatch::finishColumns","coopy/HighlightPatch.hx",327);
		HX_STACK_THIS(this);
		HX_STACK_LINE(328)
		this->needSourceColumns();
		HX_STACK_LINE(329)
		{
			HX_STACK_LINE(329)
			int _g1 = this->payloadCol;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->payloadTop;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(329)
			while(((_g1 < _g))){
				HX_STACK_LINE(329)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(330)
				::String mod = this->modifier->get(i);		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(331)
				::String hdr = this->header->get(i);		HX_STACK_VAR(hdr,"hdr");
				HX_STACK_LINE(332)
				if (((mod == HX_CSTRING("---")))){
					HX_STACK_LINE(334)
					int at = this->patchInSource->get(i);		HX_STACK_VAR(at,"at");
					HX_STACK_LINE(335)
					::coopy::HighlightPatchUnit mod1 = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod1,"mod1");
					HX_STACK_LINE(336)
					mod1->rem = true;
					HX_STACK_LINE(337)
					mod1->sourceRow = at;
					HX_STACK_LINE(338)
					mod1->patchRow = i;
					HX_STACK_LINE(339)
					this->cmods->push(mod1);
				}
				else{
					HX_STACK_LINE(340)
					if (((mod == HX_CSTRING("+++")))){
						HX_STACK_LINE(342)
						::coopy::HighlightPatchUnit mod1 = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod1,"mod1");
						HX_STACK_LINE(343)
						mod1->add = true;
						HX_STACK_LINE(344)
						int prev = (int)-1;		HX_STACK_VAR(prev,"prev");
						HX_STACK_LINE(345)
						bool cont = false;		HX_STACK_VAR(cont,"cont");
						HX_STACK_LINE(346)
						if (((i > this->payloadCol))){
							HX_STACK_LINE(346)
							if (((this->modifier->get(i) == this->modifier->get((i - (int)1))))){
								HX_STACK_LINE(347)
								prev = (int)-2;
							}
							else{
								HX_STACK_LINE(350)
								Dynamic p = this->patchInSource->get((i - (int)1));		HX_STACK_VAR(p,"p");
								HX_STACK_LINE(351)
								prev = (  (((p == null()))) ? Dynamic((int)-1) : Dynamic(p) );
							}
						}
						HX_STACK_LINE(354)
						if (((prev == (int)-2))){
							HX_STACK_LINE(354)
							mod1->sourceRow = this->cmods->__get((this->cmods->length - (int)1))->sourceRow;
						}
						else{
							HX_STACK_LINE(356)
							mod1->sourceRow = (prev + (int)1);
						}
						HX_STACK_LINE(359)
						mod1->patchRow = i;
						HX_STACK_LINE(360)
						this->cmods->push(mod1);
					}
				}
			}
		}
		HX_STACK_LINE(363)
		Array< int > fate = Array_obj< int >::__new();		HX_STACK_VAR(fate,"fate");
		HX_STACK_LINE(364)
		int len = this->processMods(this->cmods,fate,this->source->__Field(HX_CSTRING("get_width"),true)());		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(365)
		this->source->insertOrDeleteColumns(fate,len);
		HX_STACK_LINE(366)
		{
			HX_STACK_LINE(366)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::coopy::HighlightPatchUnit > _g1 = this->cmods;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(366)
			while(((_g < _g1->length))){
				HX_STACK_LINE(366)
				::coopy::HighlightPatchUnit cmod = _g1->__get(_g);		HX_STACK_VAR(cmod,"cmod");
				HX_STACK_LINE(366)
				++(_g);
				HX_STACK_LINE(367)
				if ((!(cmod->rem))){
					HX_STACK_LINE(367)
					if ((cmod->add)){
						HX_STACK_LINE(373)
						{
							HX_STACK_LINE(373)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							Array< ::coopy::HighlightPatchUnit > _g3 = this->mods;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(373)
							while(((_g2 < _g3->length))){
								HX_STACK_LINE(373)
								::coopy::HighlightPatchUnit mod = _g3->__get(_g2);		HX_STACK_VAR(mod,"mod");
								HX_STACK_LINE(373)
								++(_g2);
								HX_STACK_LINE(374)
								if (((bool((mod->patchRow != (int)-1)) && bool((mod->sourceRow2 != (int)-1))))){
									HX_STACK_LINE(375)
									Dynamic d = this->patch->getCell(cmod->patchRow,mod->patchRow);		HX_STACK_VAR(d,"d");
									HX_STACK_LINE(377)
									this->source->setCell(cmod->sourceRow2,mod->sourceRow2,d);
								}
							}
						}
						HX_STACK_LINE(382)
						::String hdr = this->header->get(cmod->patchRow);		HX_STACK_VAR(hdr,"hdr");
						HX_STACK_LINE(383)
						this->source->setCell(cmod->sourceRow2,(int)0,this->view->toDatum(hdr));
					}
				}
			}
		}
		HX_STACK_LINE(389)
		{
			HX_STACK_LINE(389)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->source->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(389)
			while(((_g1 < _g))){
				HX_STACK_LINE(389)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(390)
				::String name = this->view->toString(this->source->getCell(i,(int)0));		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(391)
				::String next_name = this->headerRename->get(name);		HX_STACK_VAR(next_name,"next_name");
				HX_STACK_LINE(392)
				if (((next_name == null()))){
					HX_STACK_LINE(392)
					continue;
				}
				HX_STACK_LINE(393)
				this->source->setCell(i,(int)0,this->view->toDatum(next_name));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,finishColumns,(void))

Void HighlightPatch_obj::finishRows( ){
{
		HX_STACK_PUSH("HighlightPatch::finishRows","coopy/HighlightPatch.hx",286);
		HX_STACK_THIS(this);
		HX_STACK_LINE(287)
		Array< int > fate = Array_obj< int >::__new();		HX_STACK_VAR(fate,"fate");
		HX_STACK_LINE(288)
		int len = this->processMods(this->mods,fate,this->source->__Field(HX_CSTRING("get_height"),true)());		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(289)
		this->source->insertOrDeleteRows(fate,len);
		HX_STACK_LINE(290)
		{
			HX_STACK_LINE(290)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::coopy::HighlightPatchUnit > _g1 = this->mods;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(290)
			while(((_g < _g1->length))){
				HX_STACK_LINE(290)
				::coopy::HighlightPatchUnit mod = _g1->__get(_g);		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(290)
				++(_g);
				HX_STACK_LINE(291)
				if ((!(mod->rem))){
					HX_STACK_LINE(291)
					if ((mod->add)){
						struct _Function_5_1{
							inline static Dynamic Block( ::coopy::HighlightPatch_obj *__this){
								HX_STACK_PUSH("*::closure","coopy/HighlightPatch.hx",294);
								{
									HX_STACK_LINE(294)
									Array< ::haxe::ds::StringMap > _e = Array_obj< ::haxe::ds::StringMap >::__new().Add(__this->headerPost);		HX_STACK_VAR(_e,"_e");

									HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_6_1,Array< ::haxe::ds::StringMap >,_e)
									Dynamic run(){
										HX_STACK_PUSH("*::_Function_6_1","coopy/HighlightPatch.hx",294);
										{
											HX_STACK_LINE(294)
											return _e->__get((int)0)->iterator();
										}
										return null();
									}
									HX_END_LOCAL_FUNC0(return)

									HX_STACK_LINE(294)
									return  Dynamic(new _Function_6_1(_e));
								}
								return null();
							}
						};
						HX_STACK_LINE(293)
						for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >((_Function_5_1::Block(this))());  __it->hasNext(); ){
							int c = __it->next();
							{
								HX_STACK_LINE(295)
								int offset = this->patchInSource->get(c);		HX_STACK_VAR(offset,"offset");
								HX_STACK_LINE(296)
								if (((offset >= (int)0))){
									HX_STACK_LINE(296)
									this->source->setCell(offset,mod->sourceRow2,this->patch->getCell(c,mod->patchRow));
								}
							}
;
						}
					}
					else{
						HX_STACK_LINE(302)
						if ((!(((bool(mod->rem) || bool(mod->pad)))))){
							HX_STACK_LINE(304)
							this->currentRow = mod->patchRow;
							HX_STACK_LINE(305)
							this->checkAct();
							HX_STACK_LINE(306)
							if ((!(this->actIsUpdate))){
								HX_STACK_LINE(306)
								continue;
							}
							struct _Function_6_1{
								inline static Dynamic Block( ::coopy::HighlightPatch_obj *__this){
									HX_STACK_PUSH("*::closure","coopy/HighlightPatch.hx",307);
									{
										HX_STACK_LINE(307)
										Array< ::haxe::ds::StringMap > _e = Array_obj< ::haxe::ds::StringMap >::__new().Add(__this->headerPre);		HX_STACK_VAR(_e,"_e");

										HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_7_1,Array< ::haxe::ds::StringMap >,_e)
										Dynamic run(){
											HX_STACK_PUSH("*::_Function_7_1","coopy/HighlightPatch.hx",307);
											{
												HX_STACK_LINE(307)
												return _e->__get((int)0)->iterator();
											}
											return null();
										}
										HX_END_LOCAL_FUNC0(return)

										HX_STACK_LINE(307)
										return  Dynamic(new _Function_7_1(_e));
									}
									return null();
								}
							};
							HX_STACK_LINE(307)
							for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >((_Function_6_1::Block(this))());  __it->hasNext(); ){
								int c = __it->next();
								{
									HX_STACK_LINE(309)
									::String txt = this->view->toString(this->patch->getCell(c,mod->patchRow));		HX_STACK_VAR(txt,"txt");
									HX_STACK_LINE(310)
									int at = txt.indexOf(this->actBaseCache,null());		HX_STACK_VAR(at,"at");
									HX_STACK_LINE(311)
									if (((at < (int)0))){
										HX_STACK_LINE(311)
										continue;
									}
									HX_STACK_LINE(312)
									if ((this->actIsConflicted)){
										HX_STACK_LINE(313)
										int at2 = txt.indexOf(this->actCache,null());		HX_STACK_VAR(at2,"at2");
										HX_STACK_LINE(314)
										if (((at2 >= (int)0))){
											HX_STACK_LINE(314)
											continue;
										}
									}
									HX_STACK_LINE(316)
									txt = txt.substr((at + this->actBaseCache.length),null());
									HX_STACK_LINE(317)
									Dynamic d = this->view->toDatum(this->csv->parseSingleCell(txt));		HX_STACK_VAR(d,"d");
									HX_STACK_LINE(318)
									this->source->setCell(this->patchInSource->get(c),mod->sourceRow2,d);
								}
;
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,finishRows,(void))

int HighlightPatch_obj::processMods( Array< ::coopy::HighlightPatchUnit > rmods,Array< int > fate,int len){
	HX_STACK_PUSH("HighlightPatch::processMods","coopy/HighlightPatch.hx",242);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rmods,"rmods");
	HX_STACK_ARG(fate,"fate");
	HX_STACK_ARG(len,"len");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	int run(Dynamic a,Dynamic b){
		HX_STACK_PUSH("*::_Function_1_1","coopy/HighlightPatch.hx",243);
		HX_STACK_ARG(a,"a");
		HX_STACK_ARG(b,"b");
		{
			HX_STACK_LINE(243)
			if (((bool((a->__Field(HX_CSTRING("sourceRow"),true) == (int)-1)) && bool((b->__Field(HX_CSTRING("sourceRow"),true) != (int)-1))))){
				HX_STACK_LINE(243)
				return (int)1;
			}
			HX_STACK_LINE(243)
			if (((bool((a->__Field(HX_CSTRING("sourceRow"),true) != (int)-1)) && bool((b->__Field(HX_CSTRING("sourceRow"),true) == (int)-1))))){
				HX_STACK_LINE(243)
				return (int)-1;
			}
			HX_STACK_LINE(243)
			if (((a->__Field(HX_CSTRING("sourceRow"),true) > b->__Field(HX_CSTRING("sourceRow"),true)))){
				HX_STACK_LINE(243)
				return (int)1;
			}
			HX_STACK_LINE(243)
			if (((a->__Field(HX_CSTRING("sourceRow"),true) < b->__Field(HX_CSTRING("sourceRow"),true)))){
				HX_STACK_LINE(243)
				return (int)-1;
			}
			HX_STACK_LINE(243)
			if (((a->__Field(HX_CSTRING("patchRow"),true) > b->__Field(HX_CSTRING("patchRow"),true)))){
				HX_STACK_LINE(243)
				return (int)1;
			}
			HX_STACK_LINE(243)
			if (((a->__Field(HX_CSTRING("patchRow"),true) < b->__Field(HX_CSTRING("patchRow"),true)))){
				HX_STACK_LINE(243)
				return (int)-1;
			}
			HX_STACK_LINE(243)
			return (int)0;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(243)
	Dynamic sorter =  Dynamic(new _Function_1_1());		HX_STACK_VAR(sorter,"sorter");
	HX_STACK_LINE(244)
	this->mods->sort(sorter);
	HX_STACK_LINE(245)
	int offset = (int)0;		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(246)
	int last = (int)0;		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(247)
	int target = (int)0;		HX_STACK_VAR(target,"target");
	HX_STACK_LINE(248)
	{
		HX_STACK_LINE(248)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(248)
		while(((_g < rmods->length))){
			HX_STACK_LINE(248)
			::coopy::HighlightPatchUnit mod = rmods->__get(_g);		HX_STACK_VAR(mod,"mod");
			HX_STACK_LINE(248)
			++(_g);
			HX_STACK_LINE(250)
			if (((last != (int)-1))){
				HX_STACK_LINE(251)
				int _g2 = last;		HX_STACK_VAR(_g2,"_g2");
				int _g1 = mod->sourceRow;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(251)
				while(((_g2 < _g1))){
					HX_STACK_LINE(251)
					int i = (_g2)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(252)
					fate->push((i + offset));
					HX_STACK_LINE(253)
					(target)++;
					HX_STACK_LINE(254)
					(last)++;
				}
			}
			HX_STACK_LINE(257)
			if ((mod->rem)){
				HX_STACK_LINE(258)
				fate->push((int)-1);
				HX_STACK_LINE(259)
				(offset)--;
			}
			else{
				HX_STACK_LINE(260)
				if ((mod->add)){
					HX_STACK_LINE(261)
					mod->sourceRow2 = target;
					HX_STACK_LINE(262)
					(target)++;
					HX_STACK_LINE(263)
					(offset)++;
				}
				else{
					HX_STACK_LINE(264)
					mod->sourceRow2 = target;
				}
			}
			HX_STACK_LINE(267)
			if (((mod->sourceRow >= (int)0))){
				HX_STACK_LINE(268)
				last = mod->sourceRow;
				HX_STACK_LINE(269)
				if ((mod->rem)){
					HX_STACK_LINE(269)
					(last)++;
				}
			}
			else{
				HX_STACK_LINE(270)
				last = (int)-1;
			}
		}
	}
	HX_STACK_LINE(274)
	if (((last != (int)-1))){
		HX_STACK_LINE(275)
		int _g = last;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(275)
		while(((_g < len))){
			HX_STACK_LINE(275)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(276)
			fate->push((i + offset));
			HX_STACK_LINE(277)
			(target)++;
			HX_STACK_LINE(278)
			(last)++;
		}
	}
	HX_STACK_LINE(283)
	return (len + offset);
}


HX_DEFINE_DYNAMIC_FUNC3(HighlightPatch_obj,processMods,return )

::String HighlightPatch_obj::getRowString( int c){
	HX_STACK_PUSH("HighlightPatch::getRowString","coopy/HighlightPatch.hx",234);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(235)
	Dynamic at = this->sourceInPatch->get(c);		HX_STACK_VAR(at,"at");
	HX_STACK_LINE(236)
	if (((at == null()))){
		HX_STACK_LINE(236)
		return HX_CSTRING("NOT_FOUND");
	}
	HX_STACK_LINE(237)
	return this->getPreString(this->getString(at));
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getRowString,return )

::String HighlightPatch_obj::getPreString( ::String txt){
	HX_STACK_PUSH("HighlightPatch::getPreString","coopy/HighlightPatch.hx",226);
	HX_STACK_THIS(this);
	HX_STACK_ARG(txt,"txt");
	HX_STACK_LINE(227)
	this->checkAct();
	HX_STACK_LINE(228)
	if ((!(this->actIsUpdate))){
		HX_STACK_LINE(228)
		return txt;
	}
	HX_STACK_LINE(229)
	if ((!(this->actIsConflicted))){
		HX_STACK_LINE(229)
		return txt.split(this->actCache)->__get((int)0);
	}
	HX_STACK_LINE(230)
	if (((txt.indexOf(this->actCache,null()) >= (int)0))){
		HX_STACK_LINE(230)
		return txt.split(this->actCache)->__get((int)0);
	}
	HX_STACK_LINE(231)
	return txt.split(this->actBaseCache)->__get((int)0);
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getPreString,return )

Void HighlightPatch_obj::checkAct( ){
{
		HX_STACK_PUSH("HighlightPatch::checkAct","coopy/HighlightPatch.hx",212);
		HX_STACK_THIS(this);
		HX_STACK_LINE(213)
		::String act = this->getString((int)0);		HX_STACK_VAR(act,"act");
		HX_STACK_LINE(214)
		if (((act != this->actCache))){
			HX_STACK_LINE(215)
			this->actCache = act;
			HX_STACK_LINE(216)
			this->actIsUpdate = (this->actCache.indexOf(HX_CSTRING("->"),null()) >= (int)0);
			HX_STACK_LINE(217)
			this->actIsConflicted = (this->actCache.indexOf(HX_CSTRING("!"),null()) >= (int)0);
			HX_STACK_LINE(218)
			if ((this->actIsConflicted)){
				HX_STACK_LINE(218)
				this->actBaseCache = this->actCache.split(HX_CSTRING("!"))->__get((int)1);
			}
			else{
				HX_STACK_LINE(220)
				this->actBaseCache = this->actCache;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,checkAct,(void))

Void HighlightPatch_obj::applyPad( ){
{
		HX_STACK_PUSH("HighlightPatch::applyPad","coopy/HighlightPatch.hx",201);
		HX_STACK_THIS(this);
		HX_STACK_LINE(202)
		this->needSourceIndex();
		HX_STACK_LINE(203)
		int at = this->lookUp();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(204)
		if (((at == (int)-1))){
			HX_STACK_LINE(204)
			return null();
		}
		HX_STACK_LINE(205)
		::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
		HX_STACK_LINE(206)
		mod->pad = true;
		HX_STACK_LINE(207)
		mod->sourceRow = at;
		HX_STACK_LINE(208)
		mod->patchRow = this->currentRow;
		HX_STACK_LINE(209)
		this->mods->push(mod);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyPad,(void))

Void HighlightPatch_obj::applyDelete( ){
{
		HX_STACK_PUSH("HighlightPatch::applyDelete","coopy/HighlightPatch.hx",190);
		HX_STACK_THIS(this);
		HX_STACK_LINE(191)
		this->needSourceIndex();
		HX_STACK_LINE(192)
		int at = this->lookUp();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(193)
		if (((at == (int)-1))){
			HX_STACK_LINE(193)
			return null();
		}
		HX_STACK_LINE(194)
		::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
		HX_STACK_LINE(195)
		mod->rem = true;
		HX_STACK_LINE(196)
		mod->sourceRow = at;
		HX_STACK_LINE(197)
		mod->patchRow = this->currentRow;
		HX_STACK_LINE(198)
		this->mods->push(mod);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyDelete,(void))

int HighlightPatch_obj::lookUp( ){
	HX_STACK_PUSH("HighlightPatch::lookUp","coopy/HighlightPatch.hx",181);
	HX_STACK_THIS(this);
	HX_STACK_LINE(182)
	{
		HX_STACK_LINE(182)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::coopy::IndexPair > _g1 = this->indexes;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(182)
		while(((_g < _g1->length))){
			HX_STACK_LINE(182)
			::coopy::IndexPair idx = _g1->__get(_g);		HX_STACK_VAR(idx,"idx");
			HX_STACK_LINE(182)
			++(_g);
			HX_STACK_LINE(183)
			::coopy::CrossMatch match = idx->queryByContent(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(match,"match");
			HX_STACK_LINE(184)
			if (((match->spot_a != (int)1))){
				HX_STACK_LINE(184)
				continue;
			}
			HX_STACK_LINE(185)
			return match->item_a->lst->__get((int)0);
		}
	}
	HX_STACK_LINE(187)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,lookUp,return )

Void HighlightPatch_obj::applyInsert( ){
{
		HX_STACK_PUSH("HighlightPatch::applyInsert","coopy/HighlightPatch.hx",157);
		HX_STACK_THIS(this);
		HX_STACK_LINE(158)
		this->needSourceIndex();
		HX_STACK_LINE(159)
		::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
		HX_STACK_LINE(160)
		mod->add = true;
		HX_STACK_LINE(161)
		int prev = (int)-1;		HX_STACK_VAR(prev,"prev");
		HX_STACK_LINE(162)
		bool cont = false;		HX_STACK_VAR(cont,"cont");
		HX_STACK_LINE(163)
		if (((this->currentRow > (int)0))){
			HX_STACK_LINE(163)
			if ((this->view->equals(this->patch->getCell((int)0,this->currentRow),this->patch->getCell((int)0,(this->currentRow - (int)1))))){
				HX_STACK_LINE(164)
				prev = (int)-2;
			}
			else{
				HX_STACK_LINE(167)
				(this->currentRow)--;
				HX_STACK_LINE(168)
				prev = this->lookUp();
				HX_STACK_LINE(169)
				(this->currentRow)++;
			}
		}
		HX_STACK_LINE(172)
		if (((prev == (int)-2))){
			HX_STACK_LINE(172)
			mod->sourceRow = this->mods->__get((this->mods->length - (int)1))->sourceRow;
		}
		else{
			HX_STACK_LINE(174)
			mod->sourceRow = (prev + (int)1);
		}
		HX_STACK_LINE(177)
		mod->patchRow = this->currentRow;
		HX_STACK_LINE(178)
		this->mods->push(mod);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyInsert,(void))

Void HighlightPatch_obj::applyUpdate( ){
{
		HX_STACK_PUSH("HighlightPatch::applyUpdate","coopy/HighlightPatch.hx",147);
		HX_STACK_THIS(this);
		HX_STACK_LINE(148)
		this->needSourceIndex();
		HX_STACK_LINE(149)
		int at = this->lookUp();		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(150)
		if (((at == (int)-1))){
			HX_STACK_LINE(150)
			return null();
		}
		HX_STACK_LINE(151)
		::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
		HX_STACK_LINE(152)
		mod->sourceRow = at;
		HX_STACK_LINE(153)
		mod->patchRow = this->currentRow;
		HX_STACK_LINE(154)
		this->mods->push(mod);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyUpdate,(void))

Void HighlightPatch_obj::applyHeader( ){
{
		HX_STACK_PUSH("HighlightPatch::applyHeader","coopy/HighlightPatch.hx",125);
		HX_STACK_THIS(this);
		HX_STACK_LINE(126)
		{
			HX_STACK_LINE(126)
			int _g1 = this->payloadCol;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->payloadTop;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(126)
			while(((_g1 < _g))){
				HX_STACK_LINE(126)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(127)
				::String name = this->getString(i);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(128)
				::String mod = this->modifier->get(i);		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(129)
				this->header->set(i,name);
				HX_STACK_LINE(130)
				if (((mod != null()))){
					HX_STACK_LINE(130)
					if (((mod.charCodeAt((int)0) == (int)40))){
						HX_STACK_LINE(132)
						::String prev_name = mod.substr((int)1,(mod.length - (int)2));		HX_STACK_VAR(prev_name,"prev_name");
						HX_STACK_LINE(133)
						this->headerPre->set(prev_name,i);
						HX_STACK_LINE(134)
						this->headerPost->set(name,i);
						HX_STACK_LINE(135)
						this->headerRename->set(prev_name,name);
						HX_STACK_LINE(136)
						continue;
					}
				}
				HX_STACK_LINE(139)
				if (((mod != HX_CSTRING("+++")))){
					HX_STACK_LINE(139)
					this->headerPre->set(name,i);
				}
				HX_STACK_LINE(140)
				if (((mod != HX_CSTRING("---")))){
					HX_STACK_LINE(140)
					this->headerPost->set(name,i);
				}
			}
		}
		HX_STACK_LINE(142)
		if (((this->source->__Field(HX_CSTRING("get_height"),true)() == (int)0))){
			HX_STACK_LINE(142)
			this->applyInsert();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyHeader,(void))

Void HighlightPatch_obj::applyMeta( ){
{
		HX_STACK_PUSH("HighlightPatch::applyMeta","coopy/HighlightPatch.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_LINE(119)
		int _g1 = this->payloadCol;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->payloadTop;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(119)
		while(((_g1 < _g))){
			HX_STACK_LINE(119)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(120)
			::String name = this->getString(i);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(121)
			if (((name == HX_CSTRING("")))){
				HX_STACK_LINE(121)
				continue;
			}
			HX_STACK_LINE(122)
			this->modifier->set(i,name);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyMeta,(void))

::String HighlightPatch_obj::getString( int c){
	HX_STACK_PUSH("HighlightPatch::getString","coopy/HighlightPatch.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(113)
	return this->view->toString(this->getDatum(c));
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getString,return )

Dynamic HighlightPatch_obj::getDatum( int c){
	HX_STACK_PUSH("HighlightPatch::getDatum","coopy/HighlightPatch.hx",109);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(109)
	return this->patch->getCell(c,this->currentRow);
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getDatum,return )

Void HighlightPatch_obj::applyRow( int r){
{
		HX_STACK_PUSH("HighlightPatch::applyRow","coopy/HighlightPatch.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_ARG(r,"r");
		HX_STACK_LINE(88)
		this->currentRow = r;
		HX_STACK_LINE(89)
		this->payloadCol = (int)1;
		HX_STACK_LINE(90)
		this->payloadTop = this->patch->__Field(HX_CSTRING("get_width"),true)();
		HX_STACK_LINE(91)
		this->view = this->patch->getCellView();
		HX_STACK_LINE(92)
		Dynamic dcode = this->patch->getCell((int)0,r);		HX_STACK_VAR(dcode,"dcode");
		HX_STACK_LINE(93)
		::String code = this->view->toString(dcode);		HX_STACK_VAR(code,"code");
		HX_STACK_LINE(94)
		if (((code == HX_CSTRING("@@")))){
			HX_STACK_LINE(94)
			this->applyHeader();
		}
		else{
			HX_STACK_LINE(96)
			if (((code == HX_CSTRING("+++")))){
				HX_STACK_LINE(96)
				this->applyInsert();
			}
			else{
				HX_STACK_LINE(98)
				if (((code == HX_CSTRING("---")))){
					HX_STACK_LINE(98)
					this->applyDelete();
				}
				else{
					HX_STACK_LINE(100)
					if (((code == HX_CSTRING("+")))){
						HX_STACK_LINE(100)
						this->applyPad();
					}
					else{
						HX_STACK_LINE(102)
						if (((code == HX_CSTRING("!")))){
							HX_STACK_LINE(102)
							this->applyMeta();
						}
						else{
							HX_STACK_LINE(104)
							if (((code.indexOf(HX_CSTRING("->"),null()) >= (int)0))){
								HX_STACK_LINE(104)
								this->applyUpdate();
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,applyRow,(void))

Void HighlightPatch_obj::needSourceIndex( ){
{
		HX_STACK_PUSH("HighlightPatch::needSourceIndex","coopy/HighlightPatch.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_LINE(75)
		if (((this->indexes != null()))){
			HX_STACK_LINE(75)
			return null();
		}
		HX_STACK_LINE(76)
		::coopy::TableComparisonState state = ::coopy::TableComparisonState_obj::__new();		HX_STACK_VAR(state,"state");
		HX_STACK_LINE(77)
		state->a = this->source;
		HX_STACK_LINE(78)
		state->b = this->source;
		HX_STACK_LINE(79)
		::coopy::CompareTable comp = ::coopy::CompareTable_obj::__new();		HX_STACK_VAR(comp,"comp");
		HX_STACK_LINE(80)
		comp->storeIndexes();
		HX_STACK_LINE(81)
		comp->attach(state);
		HX_STACK_LINE(82)
		comp->align();
		HX_STACK_LINE(83)
		this->indexes = comp->getIndexes();
		HX_STACK_LINE(84)
		this->needSourceColumns();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,needSourceIndex,(void))

Void HighlightPatch_obj::needSourceColumns( ){
{
		HX_STACK_PUSH("HighlightPatch::needSourceColumns","coopy/HighlightPatch.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_LINE(61)
		if ((this->haveSourceColumns)){
			HX_STACK_LINE(61)
			return null();
		}
		HX_STACK_LINE(63)
		::coopy::View av = this->source->getCellView();		HX_STACK_VAR(av,"av");
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->source->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(64)
			while(((_g1 < _g))){
				HX_STACK_LINE(64)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(65)
				::String name = av->toString(this->source->getCell(i,(int)0));		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(66)
				Dynamic at = this->headerPre->get(name);		HX_STACK_VAR(at,"at");
				HX_STACK_LINE(67)
				if (((at == null()))){
					HX_STACK_LINE(67)
					continue;
				}
				HX_STACK_LINE(68)
				this->sourceInPatch->set(i,at);
				HX_STACK_LINE(69)
				this->patchInSource->set(at,i);
			}
		}
		HX_STACK_LINE(71)
		this->haveSourceColumns = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,needSourceColumns,(void))

bool HighlightPatch_obj::apply( ){
	HX_STACK_PUSH("HighlightPatch::apply","coopy/HighlightPatch.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_LINE(51)
	if (((this->patch->__Field(HX_CSTRING("get_width"),true)() < (int)2))){
		HX_STACK_LINE(51)
		return true;
	}
	HX_STACK_LINE(52)
	{
		HX_STACK_LINE(52)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->patch->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(52)
		while(((_g1 < _g))){
			HX_STACK_LINE(52)
			int r = (_g1)++;		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(53)
			this->applyRow(r);
		}
	}
	HX_STACK_LINE(55)
	this->finishRows();
	HX_STACK_LINE(56)
	this->finishColumns();
	HX_STACK_LINE(57)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,apply,return )


HighlightPatch_obj::HighlightPatch_obj()
{
}

void HighlightPatch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HighlightPatch);
	HX_MARK_MEMBER_NAME(csv,"csv");
	HX_MARK_MEMBER_NAME(actIsConflicted,"actIsConflicted");
	HX_MARK_MEMBER_NAME(actIsUpdate,"actIsUpdate");
	HX_MARK_MEMBER_NAME(actBaseCache,"actBaseCache");
	HX_MARK_MEMBER_NAME(actCache,"actCache");
	HX_MARK_MEMBER_NAME(haveSourceColumns,"haveSourceColumns");
	HX_MARK_MEMBER_NAME(cmods,"cmods");
	HX_MARK_MEMBER_NAME(mods,"mods");
	HX_MARK_MEMBER_NAME(patchInSource,"patchInSource");
	HX_MARK_MEMBER_NAME(sourceInPatch,"sourceInPatch");
	HX_MARK_MEMBER_NAME(indexes,"indexes");
	HX_MARK_MEMBER_NAME(modifier,"modifier");
	HX_MARK_MEMBER_NAME(headerRename,"headerRename");
	HX_MARK_MEMBER_NAME(headerPost,"headerPost");
	HX_MARK_MEMBER_NAME(headerPre,"headerPre");
	HX_MARK_MEMBER_NAME(header,"header");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(payloadTop,"payloadTop");
	HX_MARK_MEMBER_NAME(payloadCol,"payloadCol");
	HX_MARK_MEMBER_NAME(currentRow,"currentRow");
	HX_MARK_MEMBER_NAME(patch,"patch");
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_END_CLASS();
}

void HighlightPatch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(csv,"csv");
	HX_VISIT_MEMBER_NAME(actIsConflicted,"actIsConflicted");
	HX_VISIT_MEMBER_NAME(actIsUpdate,"actIsUpdate");
	HX_VISIT_MEMBER_NAME(actBaseCache,"actBaseCache");
	HX_VISIT_MEMBER_NAME(actCache,"actCache");
	HX_VISIT_MEMBER_NAME(haveSourceColumns,"haveSourceColumns");
	HX_VISIT_MEMBER_NAME(cmods,"cmods");
	HX_VISIT_MEMBER_NAME(mods,"mods");
	HX_VISIT_MEMBER_NAME(patchInSource,"patchInSource");
	HX_VISIT_MEMBER_NAME(sourceInPatch,"sourceInPatch");
	HX_VISIT_MEMBER_NAME(indexes,"indexes");
	HX_VISIT_MEMBER_NAME(modifier,"modifier");
	HX_VISIT_MEMBER_NAME(headerRename,"headerRename");
	HX_VISIT_MEMBER_NAME(headerPost,"headerPost");
	HX_VISIT_MEMBER_NAME(headerPre,"headerPre");
	HX_VISIT_MEMBER_NAME(header,"header");
	HX_VISIT_MEMBER_NAME(view,"view");
	HX_VISIT_MEMBER_NAME(payloadTop,"payloadTop");
	HX_VISIT_MEMBER_NAME(payloadCol,"payloadCol");
	HX_VISIT_MEMBER_NAME(currentRow,"currentRow");
	HX_VISIT_MEMBER_NAME(patch,"patch");
	HX_VISIT_MEMBER_NAME(source,"source");
}

Dynamic HighlightPatch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"csv") ) { return csv; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mods") ) { return mods; }
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		if (HX_FIELD_EQ(inName,"cmods") ) { return cmods; }
		if (HX_FIELD_EQ(inName,"patch") ) { return patch; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lookUp") ) { return lookUp_dyn(); }
		if (HX_FIELD_EQ(inName,"header") ) { return header; }
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { return indexes; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"checkAct") ) { return checkAct_dyn(); }
		if (HX_FIELD_EQ(inName,"applyPad") ) { return applyPad_dyn(); }
		if (HX_FIELD_EQ(inName,"getDatum") ) { return getDatum_dyn(); }
		if (HX_FIELD_EQ(inName,"applyRow") ) { return applyRow_dyn(); }
		if (HX_FIELD_EQ(inName,"actCache") ) { return actCache; }
		if (HX_FIELD_EQ(inName,"modifier") ) { return modifier; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"applyMeta") ) { return applyMeta_dyn(); }
		if (HX_FIELD_EQ(inName,"getString") ) { return getString_dyn(); }
		if (HX_FIELD_EQ(inName,"headerPre") ) { return headerPre; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishRows") ) { return finishRows_dyn(); }
		if (HX_FIELD_EQ(inName,"headerPost") ) { return headerPost; }
		if (HX_FIELD_EQ(inName,"payloadTop") ) { return payloadTop; }
		if (HX_FIELD_EQ(inName,"payloadCol") ) { return payloadCol; }
		if (HX_FIELD_EQ(inName,"currentRow") ) { return currentRow; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"processMods") ) { return processMods_dyn(); }
		if (HX_FIELD_EQ(inName,"applyDelete") ) { return applyDelete_dyn(); }
		if (HX_FIELD_EQ(inName,"applyInsert") ) { return applyInsert_dyn(); }
		if (HX_FIELD_EQ(inName,"applyUpdate") ) { return applyUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"applyHeader") ) { return applyHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"actIsUpdate") ) { return actIsUpdate; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getRowString") ) { return getRowString_dyn(); }
		if (HX_FIELD_EQ(inName,"getPreString") ) { return getPreString_dyn(); }
		if (HX_FIELD_EQ(inName,"actBaseCache") ) { return actBaseCache; }
		if (HX_FIELD_EQ(inName,"headerRename") ) { return headerRename; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"finishColumns") ) { return finishColumns_dyn(); }
		if (HX_FIELD_EQ(inName,"patchInSource") ) { return patchInSource; }
		if (HX_FIELD_EQ(inName,"sourceInPatch") ) { return sourceInPatch; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"needSourceIndex") ) { return needSourceIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"actIsConflicted") ) { return actIsConflicted; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needSourceColumns") ) { return needSourceColumns_dyn(); }
		if (HX_FIELD_EQ(inName,"haveSourceColumns") ) { return haveSourceColumns; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HighlightPatch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"csv") ) { csv=inValue.Cast< ::coopy::Csv >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mods") ) { mods=inValue.Cast< Array< ::coopy::HighlightPatchUnit > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::coopy::View >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"cmods") ) { cmods=inValue.Cast< Array< ::coopy::HighlightPatchUnit > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"patch") ) { patch=inValue.Cast< ::coopy::Table >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"header") ) { header=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::coopy::Table >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indexes") ) { indexes=inValue.Cast< Array< ::coopy::IndexPair > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"actCache") ) { actCache=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"modifier") ) { modifier=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"headerPre") ) { headerPre=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"headerPost") ) { headerPost=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"payloadTop") ) { payloadTop=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"payloadCol") ) { payloadCol=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentRow") ) { currentRow=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"actIsUpdate") ) { actIsUpdate=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"actBaseCache") ) { actBaseCache=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"headerRename") ) { headerRename=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"patchInSource") ) { patchInSource=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sourceInPatch") ) { sourceInPatch=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"actIsConflicted") ) { actIsConflicted=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"haveSourceColumns") ) { haveSourceColumns=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HighlightPatch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("csv"));
	outFields->push(HX_CSTRING("actIsConflicted"));
	outFields->push(HX_CSTRING("actIsUpdate"));
	outFields->push(HX_CSTRING("actBaseCache"));
	outFields->push(HX_CSTRING("actCache"));
	outFields->push(HX_CSTRING("haveSourceColumns"));
	outFields->push(HX_CSTRING("cmods"));
	outFields->push(HX_CSTRING("mods"));
	outFields->push(HX_CSTRING("patchInSource"));
	outFields->push(HX_CSTRING("sourceInPatch"));
	outFields->push(HX_CSTRING("indexes"));
	outFields->push(HX_CSTRING("modifier"));
	outFields->push(HX_CSTRING("headerRename"));
	outFields->push(HX_CSTRING("headerPost"));
	outFields->push(HX_CSTRING("headerPre"));
	outFields->push(HX_CSTRING("header"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("payloadTop"));
	outFields->push(HX_CSTRING("payloadCol"));
	outFields->push(HX_CSTRING("currentRow"));
	outFields->push(HX_CSTRING("patch"));
	outFields->push(HX_CSTRING("source"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("finishColumns"),
	HX_CSTRING("finishRows"),
	HX_CSTRING("processMods"),
	HX_CSTRING("getRowString"),
	HX_CSTRING("getPreString"),
	HX_CSTRING("checkAct"),
	HX_CSTRING("applyPad"),
	HX_CSTRING("applyDelete"),
	HX_CSTRING("lookUp"),
	HX_CSTRING("applyInsert"),
	HX_CSTRING("applyUpdate"),
	HX_CSTRING("applyHeader"),
	HX_CSTRING("applyMeta"),
	HX_CSTRING("getString"),
	HX_CSTRING("getDatum"),
	HX_CSTRING("applyRow"),
	HX_CSTRING("needSourceIndex"),
	HX_CSTRING("needSourceColumns"),
	HX_CSTRING("apply"),
	HX_CSTRING("csv"),
	HX_CSTRING("actIsConflicted"),
	HX_CSTRING("actIsUpdate"),
	HX_CSTRING("actBaseCache"),
	HX_CSTRING("actCache"),
	HX_CSTRING("haveSourceColumns"),
	HX_CSTRING("cmods"),
	HX_CSTRING("mods"),
	HX_CSTRING("patchInSource"),
	HX_CSTRING("sourceInPatch"),
	HX_CSTRING("indexes"),
	HX_CSTRING("modifier"),
	HX_CSTRING("headerRename"),
	HX_CSTRING("headerPost"),
	HX_CSTRING("headerPre"),
	HX_CSTRING("header"),
	HX_CSTRING("view"),
	HX_CSTRING("payloadTop"),
	HX_CSTRING("payloadCol"),
	HX_CSTRING("currentRow"),
	HX_CSTRING("patch"),
	HX_CSTRING("source"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HighlightPatch_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HighlightPatch_obj::__mClass,"__mClass");
};

Class HighlightPatch_obj::__mClass;

void HighlightPatch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.HighlightPatch"), hx::TCanCast< HighlightPatch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HighlightPatch_obj::__boot()
{
}

} // end namespace coopy
