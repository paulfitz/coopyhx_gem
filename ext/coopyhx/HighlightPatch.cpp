#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_CellInfo
#include <coopy/CellInfo.h>
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
#ifndef INCLUDED_coopy_DiffRender
#include <coopy/DiffRender.h>
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
HX_STACK_FRAME("coopy.HighlightPatch","new",0x17563528,"coopy.HighlightPatch.new","coopy/HighlightPatch.hx",47,0x13a49627)

HX_STACK_ARG(source,"source")

HX_STACK_ARG(patch,"patch")
{
	HX_STACK_LINE(48)
	this->source = source;
	HX_STACK_LINE(49)
	this->patch = patch;
	HX_STACK_LINE(50)
	this->view = patch->getCellView();
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

hx::Object *HighlightPatch_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::coopy::Row_obj)) return operator ::coopy::Row_obj *();
	return super::__ToInterface(inType);
}

Void HighlightPatch_obj::reset( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","reset",0x8ec37097,"coopy.HighlightPatch.reset","coopy/HighlightPatch.hx",53,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(54)
		this->header = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(55)
		this->headerPre = ::haxe::ds::StringMap_obj::__new();
		HX_STACK_LINE(56)
		this->headerPost = ::haxe::ds::StringMap_obj::__new();
		HX_STACK_LINE(57)
		this->headerRename = ::haxe::ds::StringMap_obj::__new();
		HX_STACK_LINE(58)
		this->headerMove = null();
		HX_STACK_LINE(59)
		this->modifier = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(60)
		this->mods = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(61)
		this->cmods = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(62)
		this->csv = ::coopy::Csv_obj::__new();
		HX_STACK_LINE(63)
		this->rcOffset = (int)0;
		HX_STACK_LINE(64)
		this->currentRow = (int)-1;
		HX_STACK_LINE(65)
		this->rowInfo = ::coopy::CellInfo_obj::__new();
		HX_STACK_LINE(66)
		this->cellInfo = ::coopy::CellInfo_obj::__new();
		HX_STACK_LINE(68)
		this->sourceInPatchCol = this->patchInSourceCol = null();
		HX_STACK_LINE(69)
		this->patchInSourceRow = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(70)
		this->indexes = null();
		HX_STACK_LINE(71)
		this->lastSourceRow = (int)-1;
		HX_STACK_LINE(72)
		this->actions = Array_obj< ::String >::__new();
		HX_STACK_LINE(73)
		this->rowPermutation = null();
		HX_STACK_LINE(74)
		this->rowPermutationRev = null();
		HX_STACK_LINE(75)
		this->colPermutation = null();
		HX_STACK_LINE(76)
		this->colPermutationRev = null();
		HX_STACK_LINE(77)
		this->haveDroppedColumns = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,reset,(void))

bool HighlightPatch_obj::apply( ){
	HX_STACK_FRAME("coopy.HighlightPatch","apply",0xcc36ac36,"coopy.HighlightPatch.apply","coopy/HighlightPatch.hx",80,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_LINE(81)
	this->reset();
	HX_STACK_LINE(82)
	if (((this->patch->__Field(HX_CSTRING("get_width"),true)() < (int)2))){
		HX_STACK_LINE(82)
		return true;
	}
	HX_STACK_LINE(83)
	if (((this->patch->__Field(HX_CSTRING("get_height"),true)() < (int)1))){
		HX_STACK_LINE(83)
		return true;
	}
	HX_STACK_LINE(84)
	this->payloadCol = ((int)1 + this->rcOffset);
	HX_STACK_LINE(85)
	this->payloadTop = this->patch->__Field(HX_CSTRING("get_width"),true)();
	HX_STACK_LINE(86)
	::String corner = this->patch->getCellView()->toString(this->patch->getCell((int)0,(int)0));		HX_STACK_VAR(corner,"corner");
	HX_STACK_LINE(87)
	if (((corner == HX_CSTRING("@:@")))){
		HX_STACK_LINE(87)
		this->rcOffset = (int)1;
	}
	else{
		HX_STACK_LINE(87)
		this->rcOffset = (int)0;
	}
	HX_STACK_LINE(88)
	{
		HX_STACK_LINE(88)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(88)
		int _g = this->patch->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(88)
		while(((_g1 < _g))){
			HX_STACK_LINE(88)
			int r = (_g1)++;		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(89)
			::String str = this->view->toString(this->patch->getCell(this->rcOffset,r));		HX_STACK_VAR(str,"str");
			HX_STACK_LINE(90)
			this->actions->push((  (((str != null()))) ? ::String(str) : ::String(HX_CSTRING("")) ));
		}
	}
	HX_STACK_LINE(92)
	{
		HX_STACK_LINE(92)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(92)
		int _g = this->patch->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(92)
		while(((_g1 < _g))){
			HX_STACK_LINE(92)
			int r = (_g1)++;		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(93)
			this->applyRow(r);
		}
	}
	HX_STACK_LINE(95)
	this->finishRows();
	HX_STACK_LINE(96)
	this->finishColumns();
	HX_STACK_LINE(97)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,apply,return )

Void HighlightPatch_obj::needSourceColumns( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","needSourceColumns",0x7e6455d4,"coopy.HighlightPatch.needSourceColumns","coopy/HighlightPatch.hx",100,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(101)
		if (((this->sourceInPatchCol != null()))){
			HX_STACK_LINE(101)
			return null();
		}
		HX_STACK_LINE(102)
		this->sourceInPatchCol = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(103)
		this->patchInSourceCol = ::haxe::ds::IntMap_obj::__new();
		HX_STACK_LINE(106)
		::coopy::View av = this->source->getCellView();		HX_STACK_VAR(av,"av");
		HX_STACK_LINE(107)
		{
			HX_STACK_LINE(107)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(107)
			int _g = this->source->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(107)
			while(((_g1 < _g))){
				HX_STACK_LINE(107)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(108)
				::String name = av->toString(this->source->getCell(i,(int)0));		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(109)
				Dynamic at = this->headerPre->get(name);		HX_STACK_VAR(at,"at");
				HX_STACK_LINE(110)
				if (((at == null()))){
					HX_STACK_LINE(110)
					continue;
				}
				HX_STACK_LINE(111)
				this->sourceInPatchCol->set(i,at);
				HX_STACK_LINE(112)
				this->patchInSourceCol->set(at,i);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,needSourceColumns,(void))

Void HighlightPatch_obj::needSourceIndex( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","needSourceIndex",0x18f04849,"coopy.HighlightPatch.needSourceIndex","coopy/HighlightPatch.hx",116,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(117)
		if (((this->indexes != null()))){
			HX_STACK_LINE(117)
			return null();
		}
		HX_STACK_LINE(118)
		::coopy::TableComparisonState state = ::coopy::TableComparisonState_obj::__new();		HX_STACK_VAR(state,"state");
		HX_STACK_LINE(119)
		state->a = this->source;
		HX_STACK_LINE(120)
		state->b = this->source;
		HX_STACK_LINE(121)
		::coopy::CompareTable comp = ::coopy::CompareTable_obj::__new();		HX_STACK_VAR(comp,"comp");
		HX_STACK_LINE(122)
		comp->storeIndexes();
		HX_STACK_LINE(123)
		comp->attach(state);
		HX_STACK_LINE(124)
		comp->align();
		HX_STACK_LINE(125)
		this->indexes = comp->getIndexes();
		HX_STACK_LINE(126)
		this->needSourceColumns();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,needSourceIndex,(void))

Void HighlightPatch_obj::applyRow( int r){
{
		HX_STACK_FRAME("coopy.HighlightPatch","applyRow",0x0e2cf384,"coopy.HighlightPatch.applyRow","coopy/HighlightPatch.hx",129,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(130)
		this->currentRow = r;
		HX_STACK_LINE(131)
		::String code = this->actions->__get(r);		HX_STACK_VAR(code,"code");
		HX_STACK_LINE(132)
		if (((bool((r == (int)0)) && bool((this->rcOffset > (int)0))))){
		}
		else{
			HX_STACK_LINE(134)
			if (((code == HX_CSTRING("@@")))){
				HX_STACK_LINE(135)
				this->applyHeader();
				HX_STACK_LINE(136)
				this->applyAction(HX_CSTRING("@@"));
			}
			else{
				HX_STACK_LINE(137)
				if (((code == HX_CSTRING("!")))){
					HX_STACK_LINE(138)
					this->applyMeta();
				}
				else{
					HX_STACK_LINE(139)
					if (((code == HX_CSTRING("+++")))){
						HX_STACK_LINE(140)
						this->applyAction(code);
					}
					else{
						HX_STACK_LINE(141)
						if (((code == HX_CSTRING("---")))){
							HX_STACK_LINE(142)
							this->applyAction(code);
						}
						else{
							HX_STACK_LINE(143)
							if (((bool((code == HX_CSTRING("+"))) || bool((code == HX_CSTRING(":")))))){
								HX_STACK_LINE(144)
								this->applyAction(code);
							}
							else{
								HX_STACK_LINE(145)
								if (((code.indexOf(HX_CSTRING("->"),null()) >= (int)0))){
									HX_STACK_LINE(146)
									this->applyAction(HX_CSTRING("->"));
								}
								else{
									HX_STACK_LINE(148)
									this->lastSourceRow = (int)-1;
								}
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

Dynamic HighlightPatch_obj::getDatum( int c){
	HX_STACK_FRAME("coopy.HighlightPatch","getDatum",0x1d927631,"coopy.HighlightPatch.getDatum","coopy/HighlightPatch.hx",153,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(153)
	return this->patch->getCell(c,this->currentRow);
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getDatum,return )

::String HighlightPatch_obj::getString( int c){
	HX_STACK_FRAME("coopy.HighlightPatch","getString",0xb130dccf,"coopy.HighlightPatch.getString","coopy/HighlightPatch.hx",157,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(157)
	return this->view->toString(this->getDatum(c));
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getString,return )

Void HighlightPatch_obj::applyMeta( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","applyMeta",0x55d2761b,"coopy.HighlightPatch.applyMeta","coopy/HighlightPatch.hx",162,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(162)
		int _g1 = this->payloadCol;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(162)
		int _g = this->payloadTop;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(162)
		while(((_g1 < _g))){
			HX_STACK_LINE(162)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(163)
			::String name = this->getString(i);		HX_STACK_VAR(name,"name");
			HX_STACK_LINE(164)
			if (((name == HX_CSTRING("")))){
				HX_STACK_LINE(164)
				continue;
			}
			HX_STACK_LINE(165)
			this->modifier->set(i,name);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyMeta,(void))

Void HighlightPatch_obj::applyHeader( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","applyHeader",0x3b9b3663,"coopy.HighlightPatch.applyHeader","coopy/HighlightPatch.hx",169,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(170)
		{
			HX_STACK_LINE(170)
			int _g1 = this->payloadCol;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(170)
			int _g = this->payloadTop;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(170)
			while(((_g1 < _g))){
				HX_STACK_LINE(170)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(171)
				::String name = this->getString(i);		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(172)
				if (((name == HX_CSTRING("...")))){
					HX_STACK_LINE(173)
					this->modifier->set(i,HX_CSTRING("..."));
					HX_STACK_LINE(174)
					this->haveDroppedColumns = true;
					HX_STACK_LINE(175)
					continue;
				}
				HX_STACK_LINE(177)
				::String mod = this->modifier->get(i);		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(178)
				bool move = false;		HX_STACK_VAR(move,"move");
				HX_STACK_LINE(179)
				if (((mod != null()))){
					HX_STACK_LINE(180)
					if (((mod.charCodeAt((int)0) == (int)58))){
						HX_STACK_LINE(181)
						move = true;
						HX_STACK_LINE(182)
						mod = mod.substr((int)1,mod.length);
					}
				}
				HX_STACK_LINE(185)
				this->header->set(i,name);
				HX_STACK_LINE(186)
				if (((mod != null()))){
					HX_STACK_LINE(187)
					if (((mod.charCodeAt((int)0) == (int)40))){
						HX_STACK_LINE(188)
						::String prev_name = mod.substr((int)1,(mod.length - (int)2));		HX_STACK_VAR(prev_name,"prev_name");
						HX_STACK_LINE(189)
						this->headerPre->set(prev_name,i);
						HX_STACK_LINE(190)
						this->headerPost->set(name,i);
						HX_STACK_LINE(191)
						this->headerRename->set(prev_name,name);
						HX_STACK_LINE(192)
						continue;
					}
				}
				HX_STACK_LINE(195)
				if (((mod != HX_CSTRING("+++")))){
					HX_STACK_LINE(195)
					this->headerPre->set(name,i);
				}
				HX_STACK_LINE(196)
				if (((mod != HX_CSTRING("---")))){
					HX_STACK_LINE(196)
					this->headerPost->set(name,i);
				}
				HX_STACK_LINE(197)
				if ((move)){
					HX_STACK_LINE(198)
					if (((this->headerMove == null()))){
						HX_STACK_LINE(198)
						this->headerMove = ::haxe::ds::StringMap_obj::__new();
					}
					HX_STACK_LINE(199)
					this->headerMove->set(name,(int)1);
				}
			}
		}
		HX_STACK_LINE(202)
		if (((this->source->__Field(HX_CSTRING("get_height"),true)() == (int)0))){
			HX_STACK_LINE(203)
			this->applyAction(HX_CSTRING("+++"));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,applyHeader,(void))

int HighlightPatch_obj::lookUp( hx::Null< int >  __o_del){
int del = __o_del.Default(0);
	HX_STACK_FRAME("coopy.HighlightPatch","lookUp",0xb57c4ed2,"coopy.HighlightPatch.lookUp","coopy/HighlightPatch.hx",207,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(del,"del")
{
		HX_STACK_LINE(208)
		Dynamic at = this->patchInSourceRow->get((this->currentRow + del));		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(209)
		if (((at != null()))){
			HX_STACK_LINE(209)
			return at;
		}
		HX_STACK_LINE(210)
		int result = (int)-1;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(211)
		hx::AddEq(this->currentRow,del);
		HX_STACK_LINE(212)
		if (((bool((this->currentRow >= (int)0)) && bool((this->currentRow < this->patch->__Field(HX_CSTRING("get_height"),true)()))))){
			HX_STACK_LINE(213)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(213)
			Array< ::Dynamic > _g1 = this->indexes;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(213)
			while(((_g < _g1->length))){
				HX_STACK_LINE(213)
				::coopy::IndexPair idx = _g1->__get(_g).StaticCast< ::coopy::IndexPair >();		HX_STACK_VAR(idx,"idx");
				HX_STACK_LINE(213)
				++(_g);
				HX_STACK_LINE(214)
				::coopy::CrossMatch match = idx->queryByContent(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(match,"match");
				HX_STACK_LINE(215)
				if (((match->spot_a != (int)1))){
					HX_STACK_LINE(215)
					continue;
				}
				HX_STACK_LINE(216)
				result = match->item_a->lst->__get((int)0);
				HX_STACK_LINE(217)
				break;
			}
		}
		HX_STACK_LINE(220)
		{
			HX_STACK_LINE(220)
			this->patchInSourceRow->set(this->currentRow,result);
			HX_STACK_LINE(220)
			result;
		}
		HX_STACK_LINE(221)
		hx::SubEq(this->currentRow,del);
		HX_STACK_LINE(222)
		return result;
	}
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,lookUp,return )

Void HighlightPatch_obj::applyAction( ::String code){
{
		HX_STACK_FRAME("coopy.HighlightPatch","applyAction",0x54e1688c,"coopy.HighlightPatch.applyAction","coopy/HighlightPatch.hx",225,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_ARG(code,"code")
		HX_STACK_LINE(226)
		::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
		HX_STACK_LINE(227)
		mod->code = code;
		HX_STACK_LINE(228)
		mod->add = (code == HX_CSTRING("+++"));
		HX_STACK_LINE(229)
		mod->rem = (code == HX_CSTRING("---"));
		HX_STACK_LINE(230)
		mod->update = (code == HX_CSTRING("->"));
		HX_STACK_LINE(231)
		this->needSourceIndex();
		HX_STACK_LINE(232)
		if (((this->lastSourceRow == (int)-1))){
			HX_STACK_LINE(233)
			this->lastSourceRow = this->lookUp((int)-1);
		}
		HX_STACK_LINE(235)
		mod->sourcePrevRow = this->lastSourceRow;
		HX_STACK_LINE(236)
		::String nextAct = this->actions->__get((this->currentRow + (int)1));		HX_STACK_VAR(nextAct,"nextAct");
		HX_STACK_LINE(237)
		if (((bool((nextAct != HX_CSTRING("+++"))) && bool((nextAct != HX_CSTRING("...")))))){
			HX_STACK_LINE(238)
			mod->sourceNextRow = this->lookUp((int)1);
		}
		HX_STACK_LINE(240)
		if ((mod->add)){
			HX_STACK_LINE(241)
			if (((this->actions->__get((this->currentRow - (int)1)) != HX_CSTRING("+++")))){
				HX_STACK_LINE(242)
				mod->sourcePrevRow = this->lookUp((int)-1);
			}
			HX_STACK_LINE(244)
			mod->sourceRow = mod->sourcePrevRow;
			HX_STACK_LINE(245)
			if (((mod->sourceRow != (int)-1))){
				HX_STACK_LINE(245)
				mod->sourceRowOffset = (int)1;
			}
		}
		else{
			HX_STACK_LINE(247)
			mod->sourceRow = this->lastSourceRow = this->lookUp(null());
		}
		HX_STACK_LINE(249)
		if (((this->actions->__get((this->currentRow + (int)1)) == HX_CSTRING("")))){
			HX_STACK_LINE(250)
			this->lastSourceRow = mod->sourceNextRow;
		}
		HX_STACK_LINE(252)
		mod->patchRow = this->currentRow;
		HX_STACK_LINE(253)
		if (((code == HX_CSTRING("@@")))){
			HX_STACK_LINE(254)
			mod->sourceRow = (int)0;
		}
		HX_STACK_LINE(256)
		this->mods->push(mod);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,applyAction,(void))

Void HighlightPatch_obj::checkAct( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","checkAct",0x961003a2,"coopy.HighlightPatch.checkAct","coopy/HighlightPatch.hx",259,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(260)
		::String act = this->getString(this->rcOffset);		HX_STACK_VAR(act,"act");
		HX_STACK_LINE(262)
		if (((this->rowInfo->value != act))){
			HX_STACK_LINE(263)
			::coopy::DiffRender_obj::examineCell((int)0,(int)0,act,HX_CSTRING(""),act,HX_CSTRING(""),this->rowInfo);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,checkAct,(void))

::String HighlightPatch_obj::getPreString( ::String txt){
	HX_STACK_FRAME("coopy.HighlightPatch","getPreString",0xc8e69816,"coopy.HighlightPatch.getPreString","coopy/HighlightPatch.hx",267,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(txt,"txt")
	HX_STACK_LINE(268)
	this->checkAct();
	HX_STACK_LINE(270)
	if ((!(this->rowInfo->updated))){
		HX_STACK_LINE(270)
		return txt;
	}
	HX_STACK_LINE(271)
	::coopy::DiffRender_obj::examineCell((int)0,(int)0,txt,HX_CSTRING(""),this->rowInfo->value,HX_CSTRING(""),this->cellInfo);
	HX_STACK_LINE(272)
	if ((!(this->cellInfo->updated))){
		HX_STACK_LINE(272)
		return txt;
	}
	HX_STACK_LINE(273)
	return this->cellInfo->lvalue;
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getPreString,return )

::String HighlightPatch_obj::getRowString( int c){
	HX_STACK_FRAME("coopy.HighlightPatch","getRowString",0xafb46d4d,"coopy.HighlightPatch.getRowString","coopy/HighlightPatch.hx",276,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(277)
	Dynamic at = this->sourceInPatchCol->get(c);		HX_STACK_VAR(at,"at");
	HX_STACK_LINE(278)
	if (((at == null()))){
		HX_STACK_LINE(278)
		return HX_CSTRING("NOT_FOUND");
	}
	HX_STACK_LINE(279)
	return this->getPreString(this->getString(at));
}


HX_DEFINE_DYNAMIC_FUNC1(HighlightPatch_obj,getRowString,return )

int HighlightPatch_obj::sortMods( ::coopy::HighlightPatchUnit a,::coopy::HighlightPatchUnit b){
	HX_STACK_FRAME("coopy.HighlightPatch","sortMods",0x350f7427,"coopy.HighlightPatch.sortMods","coopy/HighlightPatch.hx",282,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(285)
	if (((bool((b->code == HX_CSTRING("@@"))) && bool((a->code != HX_CSTRING("@@")))))){
		HX_STACK_LINE(285)
		return (int)1;
	}
	HX_STACK_LINE(286)
	if (((bool((a->code == HX_CSTRING("@@"))) && bool((b->code != HX_CSTRING("@@")))))){
		HX_STACK_LINE(286)
		return (int)-1;
	}
	HX_STACK_LINE(287)
	if (((bool((bool((a->sourceRow == (int)-1)) && bool(!(a->add)))) && bool((b->sourceRow != (int)-1))))){
		HX_STACK_LINE(287)
		return (int)1;
	}
	HX_STACK_LINE(288)
	if (((bool((bool((a->sourceRow != (int)-1)) && bool(!(b->add)))) && bool((b->sourceRow == (int)-1))))){
		HX_STACK_LINE(288)
		return (int)-1;
	}
	HX_STACK_LINE(289)
	if ((((a->sourceRow + a->sourceRowOffset) > (b->sourceRow + b->sourceRowOffset)))){
		HX_STACK_LINE(289)
		return (int)1;
	}
	HX_STACK_LINE(290)
	if ((((a->sourceRow + a->sourceRowOffset) < (b->sourceRow + b->sourceRowOffset)))){
		HX_STACK_LINE(290)
		return (int)-1;
	}
	HX_STACK_LINE(291)
	if (((a->patchRow > b->patchRow))){
		HX_STACK_LINE(291)
		return (int)1;
	}
	HX_STACK_LINE(292)
	if (((a->patchRow < b->patchRow))){
		HX_STACK_LINE(292)
		return (int)-1;
	}
	HX_STACK_LINE(292)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(HighlightPatch_obj,sortMods,return )

int HighlightPatch_obj::processMods( Array< ::Dynamic > rmods,Array< int > fate,int len){
	HX_STACK_FRAME("coopy.HighlightPatch","processMods",0x67987248,"coopy.HighlightPatch.processMods","coopy/HighlightPatch.hx",298,0x13a49627)
	HX_STACK_THIS(this)
	HX_STACK_ARG(rmods,"rmods")
	HX_STACK_ARG(fate,"fate")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(299)
	rmods->sort(this->sortMods_dyn());
	HX_STACK_LINE(300)
	int offset = (int)0;		HX_STACK_VAR(offset,"offset");
	HX_STACK_LINE(301)
	int last = (int)-1;		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(302)
	int target = (int)0;		HX_STACK_VAR(target,"target");
	HX_STACK_LINE(303)
	{
		HX_STACK_LINE(303)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(303)
		while(((_g < rmods->length))){
			HX_STACK_LINE(303)
			::coopy::HighlightPatchUnit mod = rmods->__get(_g).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(mod,"mod");
			HX_STACK_LINE(303)
			++(_g);
			HX_STACK_LINE(304)
			if (((last != (int)-1))){
				HX_STACK_LINE(305)
				int _g2 = last;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(305)
				int _g1 = (mod->sourceRow + mod->sourceRowOffset);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(305)
				while(((_g2 < _g1))){
					HX_STACK_LINE(305)
					int i = (_g2)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(306)
					fate->push((i + offset));
					HX_STACK_LINE(307)
					(target)++;
					HX_STACK_LINE(308)
					(last)++;
				}
			}
			HX_STACK_LINE(311)
			if ((mod->rem)){
				HX_STACK_LINE(312)
				fate->push((int)-1);
				HX_STACK_LINE(313)
				(offset)--;
			}
			else{
				HX_STACK_LINE(314)
				if ((mod->add)){
					HX_STACK_LINE(315)
					mod->destRow = target;
					HX_STACK_LINE(316)
					(target)++;
					HX_STACK_LINE(317)
					(offset)++;
				}
				else{
					HX_STACK_LINE(319)
					mod->destRow = target;
				}
			}
			HX_STACK_LINE(321)
			if (((mod->sourceRow >= (int)0))){
				HX_STACK_LINE(322)
				last = (mod->sourceRow + mod->sourceRowOffset);
				HX_STACK_LINE(323)
				if ((mod->rem)){
					HX_STACK_LINE(323)
					(last)++;
				}
			}
			else{
				HX_STACK_LINE(325)
				last = (int)-1;
			}
		}
	}
	HX_STACK_LINE(328)
	if (((last != (int)-1))){
		HX_STACK_LINE(329)
		int _g = last;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(329)
		while(((_g < len))){
			HX_STACK_LINE(329)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(330)
			fate->push((i + offset));
			HX_STACK_LINE(331)
			(target)++;
			HX_STACK_LINE(332)
			(last)++;
		}
	}
	HX_STACK_LINE(335)
	return (len + offset);
}


HX_DEFINE_DYNAMIC_FUNC3(HighlightPatch_obj,processMods,return )

Void HighlightPatch_obj::computeOrdering( Array< ::Dynamic > mods,Array< int > permutation,Array< int > permutationRev,int dim){
{
		HX_STACK_FRAME("coopy.HighlightPatch","computeOrdering",0x992cac73,"coopy.HighlightPatch.computeOrdering","coopy/HighlightPatch.hx",341,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_ARG(mods,"mods")
		HX_STACK_ARG(permutation,"permutation")
		HX_STACK_ARG(permutationRev,"permutationRev")
		HX_STACK_ARG(dim,"dim")
		HX_STACK_LINE(345)
		::haxe::ds::IntMap to_unit = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(to_unit,"to_unit");
		HX_STACK_LINE(346)
		::haxe::ds::IntMap from_unit = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(from_unit,"from_unit");
		HX_STACK_LINE(347)
		::haxe::ds::IntMap meta_from_unit = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(meta_from_unit,"meta_from_unit");
		HX_STACK_LINE(348)
		int ct = (int)0;		HX_STACK_VAR(ct,"ct");
		HX_STACK_LINE(349)
		{
			HX_STACK_LINE(349)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(349)
			while(((_g < mods->length))){
				HX_STACK_LINE(349)
				::coopy::HighlightPatchUnit mod = mods->__get(_g).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(349)
				++(_g);
				HX_STACK_LINE(350)
				if (((bool(mod->add) || bool(mod->rem)))){
					HX_STACK_LINE(350)
					continue;
				}
				HX_STACK_LINE(351)
				if (((mod->sourceRow < (int)0))){
					HX_STACK_LINE(351)
					continue;
				}
				HX_STACK_LINE(352)
				if (((mod->sourcePrevRow >= (int)0))){
					HX_STACK_LINE(353)
					{
						HX_STACK_LINE(353)
						int v = mod->sourceRow;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(353)
						to_unit->set(mod->sourcePrevRow,v);
						HX_STACK_LINE(353)
						v;
					}
					HX_STACK_LINE(354)
					{
						HX_STACK_LINE(354)
						int v = mod->sourcePrevRow;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(354)
						from_unit->set(mod->sourceRow,v);
						HX_STACK_LINE(354)
						v;
					}
					HX_STACK_LINE(355)
					if ((((mod->sourcePrevRow + (int)1) != mod->sourceRow))){
						HX_STACK_LINE(356)
						(ct)++;
					}
				}
				HX_STACK_LINE(359)
				if (((mod->sourceNextRow >= (int)0))){
					HX_STACK_LINE(361)
					{
						HX_STACK_LINE(361)
						int v = mod->sourceNextRow;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(361)
						to_unit->set(mod->sourceRow,v);
						HX_STACK_LINE(361)
						v;
					}
					HX_STACK_LINE(362)
					{
						HX_STACK_LINE(362)
						int v = mod->sourceRow;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(362)
						from_unit->set(mod->sourceNextRow,v);
						HX_STACK_LINE(362)
						v;
					}
					HX_STACK_LINE(363)
					if ((((mod->sourceRow + (int)1) != mod->sourceNextRow))){
						HX_STACK_LINE(364)
						(ct)++;
					}
				}
			}
		}
		HX_STACK_LINE(379)
		if (((ct > (int)0))){
			HX_STACK_LINE(380)
			Dynamic cursor = null();		HX_STACK_VAR(cursor,"cursor");
			HX_STACK_LINE(381)
			Dynamic logical = null();		HX_STACK_VAR(logical,"logical");
			HX_STACK_LINE(382)
			Array< int > starts = Array_obj< int >::__new();		HX_STACK_VAR(starts,"starts");
			HX_STACK_LINE(383)
			{
				HX_STACK_LINE(383)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(383)
				while(((_g < dim))){
					HX_STACK_LINE(383)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(384)
					Dynamic u = from_unit->get(i);		HX_STACK_VAR(u,"u");
					HX_STACK_LINE(385)
					if (((u != null()))){
						HX_STACK_LINE(386)
						meta_from_unit->set(u,i);
						HX_STACK_LINE(386)
						i;
					}
					else{
						HX_STACK_LINE(388)
						starts->push(i);
					}
				}
			}
			HX_STACK_LINE(391)
			::haxe::ds::IntMap used = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(used,"used");
			HX_STACK_LINE(392)
			int len = (int)0;		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(393)
			{
				HX_STACK_LINE(393)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(393)
				while(((_g < dim))){
					HX_STACK_LINE(393)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(394)
					if ((meta_from_unit->exists(logical))){
						HX_STACK_LINE(395)
						cursor = meta_from_unit->get(logical);
					}
					else{
						HX_STACK_LINE(397)
						cursor = null();
					}
					HX_STACK_LINE(399)
					if (((cursor == null()))){
						HX_STACK_LINE(400)
						int v = starts->shift();		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(401)
						cursor = v;
						HX_STACK_LINE(402)
						logical = v;
					}
					HX_STACK_LINE(404)
					if (((cursor == null()))){
						HX_STACK_LINE(405)
						cursor = (int)0;
					}
					HX_STACK_LINE(407)
					while((used->exists(cursor))){
						HX_STACK_LINE(408)
						cursor = hx::Mod(((cursor + (int)1)),dim);
					}
					HX_STACK_LINE(410)
					logical = cursor;
					HX_STACK_LINE(411)
					permutationRev->push(cursor);
					HX_STACK_LINE(412)
					{
						HX_STACK_LINE(412)
						used->set(cursor,(int)1);
						HX_STACK_LINE(412)
						(int)1;
					}
				}
			}
			HX_STACK_LINE(414)
			{
				HX_STACK_LINE(414)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(414)
				int _g = permutationRev->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(414)
				while(((_g1 < _g))){
					HX_STACK_LINE(414)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(415)
					permutation[i] = (int)-1;
				}
			}
			HX_STACK_LINE(417)
			{
				HX_STACK_LINE(417)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(417)
				int _g = permutation->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(417)
				while(((_g1 < _g))){
					HX_STACK_LINE(417)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(418)
					permutation[permutationRev->__get(i)] = i;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(HighlightPatch_obj,computeOrdering,(void))

Void HighlightPatch_obj::permuteRows( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","permuteRows",0x4c01d737,"coopy.HighlightPatch.permuteRows","coopy/HighlightPatch.hx",423,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(424)
		this->rowPermutation = Array_obj< int >::__new();
		HX_STACK_LINE(425)
		this->rowPermutationRev = Array_obj< int >::__new();
		HX_STACK_LINE(426)
		this->computeOrdering(this->mods,this->rowPermutation,this->rowPermutationRev,this->source->__Field(HX_CSTRING("get_height"),true)());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,permuteRows,(void))

Void HighlightPatch_obj::finishRows( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","finishRows",0xe924cb44,"coopy.HighlightPatch.finishRows","coopy/HighlightPatch.hx",429,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(430)
		Array< int > fate = Array_obj< int >::__new();		HX_STACK_VAR(fate,"fate");
		HX_STACK_LINE(431)
		this->permuteRows();
		HX_STACK_LINE(432)
		if (((this->rowPermutation->length > (int)0))){
			HX_STACK_LINE(433)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(433)
			Array< ::Dynamic > _g1 = this->mods;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(433)
			while(((_g < _g1->length))){
				HX_STACK_LINE(433)
				::coopy::HighlightPatchUnit mod = _g1->__get(_g).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(433)
				++(_g);
				HX_STACK_LINE(434)
				if (((mod->sourceRow >= (int)0))){
					HX_STACK_LINE(435)
					mod->sourceRow = this->rowPermutation->__get(mod->sourceRow);
				}
			}
		}
		HX_STACK_LINE(440)
		if (((this->rowPermutation->length > (int)0))){
			HX_STACK_LINE(441)
			this->source->insertOrDeleteRows(this->rowPermutation,this->rowPermutation->length);
		}
		HX_STACK_LINE(444)
		int len = this->processMods(this->mods,fate,this->source->__Field(HX_CSTRING("get_height"),true)());		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(445)
		this->source->insertOrDeleteRows(fate,len);
		HX_STACK_LINE(447)
		{
			HX_STACK_LINE(447)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(447)
			Array< ::Dynamic > _g1 = this->mods;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(447)
			while(((_g < _g1->length))){
				HX_STACK_LINE(447)
				::coopy::HighlightPatchUnit mod = _g1->__get(_g).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(mod,"mod");
				HX_STACK_LINE(447)
				++(_g);
				HX_STACK_LINE(449)
				if ((!(mod->rem))){
					HX_STACK_LINE(450)
					if ((mod->add)){
						HX_STACK_LINE(451)
						for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(this->headerPost->iterator());  __it->hasNext(); ){
							int c = __it->next();
							{
								HX_STACK_LINE(452)
								Dynamic offset = this->patchInSourceCol->get(c);		HX_STACK_VAR(offset,"offset");
								HX_STACK_LINE(453)
								if (((bool((offset != null())) && bool((offset >= (int)0))))){
									HX_STACK_LINE(454)
									this->source->setCell(offset,mod->destRow,this->patch->getCell(c,mod->patchRow));
								}
							}
;
						}
					}
					else{
						HX_STACK_LINE(459)
						if ((mod->update)){
							HX_STACK_LINE(461)
							this->currentRow = mod->patchRow;
							HX_STACK_LINE(462)
							this->checkAct();
							HX_STACK_LINE(463)
							if ((!(this->rowInfo->updated))){
								HX_STACK_LINE(463)
								continue;
							}
							HX_STACK_LINE(464)
							for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(this->headerPre->iterator());  __it->hasNext(); ){
								int c = __it->next();
								{
									HX_STACK_LINE(466)
									::String txt = this->view->toString(this->patch->getCell(c,mod->patchRow));		HX_STACK_VAR(txt,"txt");
									HX_STACK_LINE(467)
									::coopy::DiffRender_obj::examineCell((int)0,(int)0,txt,HX_CSTRING(""),this->rowInfo->value,HX_CSTRING(""),this->cellInfo);
									HX_STACK_LINE(468)
									if ((!(this->cellInfo->updated))){
										HX_STACK_LINE(468)
										continue;
									}
									HX_STACK_LINE(469)
									if ((this->cellInfo->conflicted)){
										HX_STACK_LINE(469)
										continue;
									}
									HX_STACK_LINE(470)
									Dynamic d = this->view->toDatum(this->csv->parseSingleCell(this->cellInfo->rvalue));		HX_STACK_VAR(d,"d");
									HX_STACK_LINE(471)
									this->source->setCell(this->patchInSourceCol->get(c),mod->destRow,d);
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

Void HighlightPatch_obj::permuteColumns( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","permuteColumns",0xe854717f,"coopy.HighlightPatch.permuteColumns","coopy/HighlightPatch.hx",480,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(481)
		if (((this->headerMove == null()))){
			HX_STACK_LINE(481)
			return null();
		}
		HX_STACK_LINE(482)
		this->colPermutation = Array_obj< int >::__new();
		HX_STACK_LINE(483)
		this->colPermutationRev = Array_obj< int >::__new();
		HX_STACK_LINE(484)
		this->computeOrdering(this->cmods,this->colPermutation,this->colPermutationRev,this->source->__Field(HX_CSTRING("get_width"),true)());
		HX_STACK_LINE(485)
		if (((this->colPermutation->length == (int)0))){
			HX_STACK_LINE(485)
			return null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,permuteColumns,(void))

Void HighlightPatch_obj::finishColumns( ){
{
		HX_STACK_FRAME("coopy.HighlightPatch","finishColumns",0xfd19c392,"coopy.HighlightPatch.finishColumns","coopy/HighlightPatch.hx",488,0x13a49627)
		HX_STACK_THIS(this)
		HX_STACK_LINE(491)
		this->needSourceColumns();
		HX_STACK_LINE(492)
		{
			HX_STACK_LINE(492)
			int _g1 = this->payloadCol;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(492)
			int _g = this->payloadTop;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(492)
			while(((_g1 < _g))){
				HX_STACK_LINE(492)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(493)
				::String act = this->modifier->get(i);		HX_STACK_VAR(act,"act");
				HX_STACK_LINE(494)
				::String hdr = this->header->get(i);		HX_STACK_VAR(hdr,"hdr");
				HX_STACK_LINE(495)
				if (((act == null()))){
					HX_STACK_LINE(495)
					act = HX_CSTRING("");
				}
				HX_STACK_LINE(496)
				if (((act == HX_CSTRING("---")))){
					HX_STACK_LINE(497)
					int at = this->patchInSourceCol->get(i);		HX_STACK_VAR(at,"at");
					HX_STACK_LINE(498)
					::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
					HX_STACK_LINE(499)
					mod->code = act;
					HX_STACK_LINE(500)
					mod->rem = true;
					HX_STACK_LINE(501)
					mod->sourceRow = at;
					HX_STACK_LINE(502)
					mod->patchRow = i;
					HX_STACK_LINE(503)
					this->cmods->push(mod);
				}
				else{
					HX_STACK_LINE(504)
					if (((act == HX_CSTRING("+++")))){
						HX_STACK_LINE(505)
						::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
						HX_STACK_LINE(506)
						mod->code = act;
						HX_STACK_LINE(507)
						mod->add = true;
						HX_STACK_LINE(508)
						int prev = (int)-1;		HX_STACK_VAR(prev,"prev");
						HX_STACK_LINE(509)
						bool cont = false;		HX_STACK_VAR(cont,"cont");
						HX_STACK_LINE(510)
						mod->sourceRow = (int)-1;
						HX_STACK_LINE(511)
						if (((this->cmods->length > (int)0))){
							HX_STACK_LINE(512)
							mod->sourceRow = this->cmods->__get((this->cmods->length - (int)1)).StaticCast< ::coopy::HighlightPatchUnit >()->sourceRow;
						}
						HX_STACK_LINE(514)
						if (((mod->sourceRow != (int)-1))){
							HX_STACK_LINE(515)
							mod->sourceRowOffset = (int)1;
						}
						HX_STACK_LINE(517)
						mod->patchRow = i;
						HX_STACK_LINE(518)
						this->cmods->push(mod);
					}
					else{
						HX_STACK_LINE(519)
						if (((act != HX_CSTRING("...")))){
							HX_STACK_LINE(520)
							::coopy::HighlightPatchUnit mod = ::coopy::HighlightPatchUnit_obj::__new();		HX_STACK_VAR(mod,"mod");
							HX_STACK_LINE(521)
							mod->code = act;
							HX_STACK_LINE(522)
							mod->patchRow = i;
							HX_STACK_LINE(523)
							mod->sourceRow = this->patchInSourceCol->get(i);
							HX_STACK_LINE(524)
							this->cmods->push(mod);
						}
					}
				}
			}
		}
		HX_STACK_LINE(527)
		int at = (int)-1;		HX_STACK_VAR(at,"at");
		HX_STACK_LINE(528)
		int rat = (int)-1;		HX_STACK_VAR(rat,"rat");
		HX_STACK_LINE(529)
		{
			HX_STACK_LINE(529)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(529)
			int _g = (this->cmods->length - (int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(529)
			while(((_g1 < _g))){
				HX_STACK_LINE(529)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(530)
				::String icode = this->cmods->__get(i).StaticCast< ::coopy::HighlightPatchUnit >()->code;		HX_STACK_VAR(icode,"icode");
				HX_STACK_LINE(531)
				if (((bool((icode != HX_CSTRING("+++"))) && bool((icode != HX_CSTRING("---")))))){
					HX_STACK_LINE(532)
					at = this->cmods->__get(i).StaticCast< ::coopy::HighlightPatchUnit >()->sourceRow;
				}
				HX_STACK_LINE(534)
				this->cmods->__get((i + (int)1)).StaticCast< ::coopy::HighlightPatchUnit >()->sourcePrevRow = at;
				HX_STACK_LINE(535)
				int j = ((this->cmods->length - (int)1) - i);		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(536)
				::String jcode = this->cmods->__get(j).StaticCast< ::coopy::HighlightPatchUnit >()->code;		HX_STACK_VAR(jcode,"jcode");
				HX_STACK_LINE(537)
				if (((bool((jcode != HX_CSTRING("+++"))) && bool((jcode != HX_CSTRING("---")))))){
					HX_STACK_LINE(538)
					rat = this->cmods->__get(j).StaticCast< ::coopy::HighlightPatchUnit >()->sourceRow;
				}
				HX_STACK_LINE(540)
				this->cmods->__get((j - (int)1)).StaticCast< ::coopy::HighlightPatchUnit >()->sourceNextRow = rat;
			}
		}
		HX_STACK_LINE(542)
		Array< int > fate = Array_obj< int >::__new();		HX_STACK_VAR(fate,"fate");
		HX_STACK_LINE(543)
		this->permuteColumns();
		HX_STACK_LINE(544)
		if (((this->headerMove != null()))){
			HX_STACK_LINE(545)
			if (((this->colPermutation->length > (int)0))){
				HX_STACK_LINE(546)
				{
					HX_STACK_LINE(546)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(546)
					Array< ::Dynamic > _g1 = this->cmods;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(546)
					while(((_g < _g1->length))){
						HX_STACK_LINE(546)
						::coopy::HighlightPatchUnit mod = _g1->__get(_g).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(mod,"mod");
						HX_STACK_LINE(546)
						++(_g);
						HX_STACK_LINE(547)
						if (((mod->sourceRow >= (int)0))){
							HX_STACK_LINE(548)
							mod->sourceRow = this->colPermutation->__get(mod->sourceRow);
						}
					}
				}
				HX_STACK_LINE(551)
				this->source->insertOrDeleteColumns(this->colPermutation,this->colPermutation->length);
			}
		}
		HX_STACK_LINE(555)
		int len = this->processMods(this->cmods,fate,this->source->__Field(HX_CSTRING("get_width"),true)());		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(556)
		this->source->insertOrDeleteColumns(fate,len);
		HX_STACK_LINE(557)
		{
			HX_STACK_LINE(557)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(557)
			Array< ::Dynamic > _g1 = this->cmods;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(557)
			while(((_g < _g1->length))){
				HX_STACK_LINE(557)
				::coopy::HighlightPatchUnit cmod = _g1->__get(_g).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(cmod,"cmod");
				HX_STACK_LINE(557)
				++(_g);
				HX_STACK_LINE(558)
				if ((!(cmod->rem))){
					HX_STACK_LINE(559)
					if ((cmod->add)){
						HX_STACK_LINE(564)
						{
							HX_STACK_LINE(564)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(564)
							Array< ::Dynamic > _g3 = this->mods;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(564)
							while(((_g2 < _g3->length))){
								HX_STACK_LINE(564)
								::coopy::HighlightPatchUnit mod = _g3->__get(_g2).StaticCast< ::coopy::HighlightPatchUnit >();		HX_STACK_VAR(mod,"mod");
								HX_STACK_LINE(564)
								++(_g2);
								HX_STACK_LINE(565)
								if (((bool((mod->patchRow != (int)-1)) && bool((mod->destRow != (int)-1))))){
									HX_STACK_LINE(566)
									Dynamic d = this->patch->getCell(cmod->patchRow,mod->patchRow);		HX_STACK_VAR(d,"d");
									HX_STACK_LINE(568)
									this->source->setCell(cmod->destRow,mod->destRow,d);
								}
							}
						}
						HX_STACK_LINE(573)
						::String hdr = this->header->get(cmod->patchRow);		HX_STACK_VAR(hdr,"hdr");
						HX_STACK_LINE(574)
						this->source->setCell(cmod->destRow,(int)0,this->view->toDatum(hdr));
					}
				}
			}
		}
		HX_STACK_LINE(580)
		{
			HX_STACK_LINE(580)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(580)
			int _g = this->source->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(580)
			while(((_g1 < _g))){
				HX_STACK_LINE(580)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(581)
				::String name = this->view->toString(this->source->getCell(i,(int)0));		HX_STACK_VAR(name,"name");
				HX_STACK_LINE(582)
				::String next_name = this->headerRename->get(name);		HX_STACK_VAR(next_name,"next_name");
				HX_STACK_LINE(583)
				if (((next_name == null()))){
					HX_STACK_LINE(583)
					continue;
				}
				HX_STACK_LINE(584)
				this->source->setCell(i,(int)0,this->view->toDatum(next_name));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HighlightPatch_obj,finishColumns,(void))


HighlightPatch_obj::HighlightPatch_obj()
{
}

void HighlightPatch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HighlightPatch);
	HX_MARK_MEMBER_NAME(source,"source");
	HX_MARK_MEMBER_NAME(patch,"patch");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(csv,"csv");
	HX_MARK_MEMBER_NAME(header,"header");
	HX_MARK_MEMBER_NAME(headerPre,"headerPre");
	HX_MARK_MEMBER_NAME(headerPost,"headerPost");
	HX_MARK_MEMBER_NAME(headerRename,"headerRename");
	HX_MARK_MEMBER_NAME(headerMove,"headerMove");
	HX_MARK_MEMBER_NAME(modifier,"modifier");
	HX_MARK_MEMBER_NAME(currentRow,"currentRow");
	HX_MARK_MEMBER_NAME(payloadCol,"payloadCol");
	HX_MARK_MEMBER_NAME(payloadTop,"payloadTop");
	HX_MARK_MEMBER_NAME(mods,"mods");
	HX_MARK_MEMBER_NAME(cmods,"cmods");
	HX_MARK_MEMBER_NAME(rowInfo,"rowInfo");
	HX_MARK_MEMBER_NAME(cellInfo,"cellInfo");
	HX_MARK_MEMBER_NAME(rcOffset,"rcOffset");
	HX_MARK_MEMBER_NAME(indexes,"indexes");
	HX_MARK_MEMBER_NAME(sourceInPatchCol,"sourceInPatchCol");
	HX_MARK_MEMBER_NAME(patchInSourceCol,"patchInSourceCol");
	HX_MARK_MEMBER_NAME(patchInSourceRow,"patchInSourceRow");
	HX_MARK_MEMBER_NAME(lastSourceRow,"lastSourceRow");
	HX_MARK_MEMBER_NAME(actions,"actions");
	HX_MARK_MEMBER_NAME(rowPermutation,"rowPermutation");
	HX_MARK_MEMBER_NAME(rowPermutationRev,"rowPermutationRev");
	HX_MARK_MEMBER_NAME(colPermutation,"colPermutation");
	HX_MARK_MEMBER_NAME(colPermutationRev,"colPermutationRev");
	HX_MARK_MEMBER_NAME(haveDroppedColumns,"haveDroppedColumns");
	HX_MARK_END_CLASS();
}

void HighlightPatch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(source,"source");
	HX_VISIT_MEMBER_NAME(patch,"patch");
	HX_VISIT_MEMBER_NAME(view,"view");
	HX_VISIT_MEMBER_NAME(csv,"csv");
	HX_VISIT_MEMBER_NAME(header,"header");
	HX_VISIT_MEMBER_NAME(headerPre,"headerPre");
	HX_VISIT_MEMBER_NAME(headerPost,"headerPost");
	HX_VISIT_MEMBER_NAME(headerRename,"headerRename");
	HX_VISIT_MEMBER_NAME(headerMove,"headerMove");
	HX_VISIT_MEMBER_NAME(modifier,"modifier");
	HX_VISIT_MEMBER_NAME(currentRow,"currentRow");
	HX_VISIT_MEMBER_NAME(payloadCol,"payloadCol");
	HX_VISIT_MEMBER_NAME(payloadTop,"payloadTop");
	HX_VISIT_MEMBER_NAME(mods,"mods");
	HX_VISIT_MEMBER_NAME(cmods,"cmods");
	HX_VISIT_MEMBER_NAME(rowInfo,"rowInfo");
	HX_VISIT_MEMBER_NAME(cellInfo,"cellInfo");
	HX_VISIT_MEMBER_NAME(rcOffset,"rcOffset");
	HX_VISIT_MEMBER_NAME(indexes,"indexes");
	HX_VISIT_MEMBER_NAME(sourceInPatchCol,"sourceInPatchCol");
	HX_VISIT_MEMBER_NAME(patchInSourceCol,"patchInSourceCol");
	HX_VISIT_MEMBER_NAME(patchInSourceRow,"patchInSourceRow");
	HX_VISIT_MEMBER_NAME(lastSourceRow,"lastSourceRow");
	HX_VISIT_MEMBER_NAME(actions,"actions");
	HX_VISIT_MEMBER_NAME(rowPermutation,"rowPermutation");
	HX_VISIT_MEMBER_NAME(rowPermutationRev,"rowPermutationRev");
	HX_VISIT_MEMBER_NAME(colPermutation,"colPermutation");
	HX_VISIT_MEMBER_NAME(colPermutationRev,"colPermutationRev");
	HX_VISIT_MEMBER_NAME(haveDroppedColumns,"haveDroppedColumns");
}

Dynamic HighlightPatch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"csv") ) { return csv; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		if (HX_FIELD_EQ(inName,"mods") ) { return mods; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"patch") ) { return patch; }
		if (HX_FIELD_EQ(inName,"cmods") ) { return cmods; }
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { return source; }
		if (HX_FIELD_EQ(inName,"header") ) { return header; }
		if (HX_FIELD_EQ(inName,"lookUp") ) { return lookUp_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rowInfo") ) { return rowInfo; }
		if (HX_FIELD_EQ(inName,"indexes") ) { return indexes; }
		if (HX_FIELD_EQ(inName,"actions") ) { return actions; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"modifier") ) { return modifier; }
		if (HX_FIELD_EQ(inName,"cellInfo") ) { return cellInfo; }
		if (HX_FIELD_EQ(inName,"rcOffset") ) { return rcOffset; }
		if (HX_FIELD_EQ(inName,"applyRow") ) { return applyRow_dyn(); }
		if (HX_FIELD_EQ(inName,"getDatum") ) { return getDatum_dyn(); }
		if (HX_FIELD_EQ(inName,"checkAct") ) { return checkAct_dyn(); }
		if (HX_FIELD_EQ(inName,"sortMods") ) { return sortMods_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"headerPre") ) { return headerPre; }
		if (HX_FIELD_EQ(inName,"getString") ) { return getString_dyn(); }
		if (HX_FIELD_EQ(inName,"applyMeta") ) { return applyMeta_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"headerPost") ) { return headerPost; }
		if (HX_FIELD_EQ(inName,"headerMove") ) { return headerMove; }
		if (HX_FIELD_EQ(inName,"currentRow") ) { return currentRow; }
		if (HX_FIELD_EQ(inName,"payloadCol") ) { return payloadCol; }
		if (HX_FIELD_EQ(inName,"payloadTop") ) { return payloadTop; }
		if (HX_FIELD_EQ(inName,"finishRows") ) { return finishRows_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"applyHeader") ) { return applyHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"applyAction") ) { return applyAction_dyn(); }
		if (HX_FIELD_EQ(inName,"processMods") ) { return processMods_dyn(); }
		if (HX_FIELD_EQ(inName,"permuteRows") ) { return permuteRows_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"headerRename") ) { return headerRename; }
		if (HX_FIELD_EQ(inName,"getPreString") ) { return getPreString_dyn(); }
		if (HX_FIELD_EQ(inName,"getRowString") ) { return getRowString_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lastSourceRow") ) { return lastSourceRow; }
		if (HX_FIELD_EQ(inName,"finishColumns") ) { return finishColumns_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rowPermutation") ) { return rowPermutation; }
		if (HX_FIELD_EQ(inName,"colPermutation") ) { return colPermutation; }
		if (HX_FIELD_EQ(inName,"permuteColumns") ) { return permuteColumns_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"needSourceIndex") ) { return needSourceIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"computeOrdering") ) { return computeOrdering_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"sourceInPatchCol") ) { return sourceInPatchCol; }
		if (HX_FIELD_EQ(inName,"patchInSourceCol") ) { return patchInSourceCol; }
		if (HX_FIELD_EQ(inName,"patchInSourceRow") ) { return patchInSourceRow; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"rowPermutationRev") ) { return rowPermutationRev; }
		if (HX_FIELD_EQ(inName,"colPermutationRev") ) { return colPermutationRev; }
		if (HX_FIELD_EQ(inName,"needSourceColumns") ) { return needSourceColumns_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"haveDroppedColumns") ) { return haveDroppedColumns; }
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
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::coopy::View >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mods") ) { mods=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"patch") ) { patch=inValue.Cast< ::coopy::Table >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cmods") ) { cmods=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"source") ) { source=inValue.Cast< ::coopy::Table >(); return inValue; }
		if (HX_FIELD_EQ(inName,"header") ) { header=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rowInfo") ) { rowInfo=inValue.Cast< ::coopy::CellInfo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexes") ) { indexes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"actions") ) { actions=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"modifier") ) { modifier=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cellInfo") ) { cellInfo=inValue.Cast< ::coopy::CellInfo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rcOffset") ) { rcOffset=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"headerPre") ) { headerPre=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"headerPost") ) { headerPost=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"headerMove") ) { headerMove=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentRow") ) { currentRow=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"payloadCol") ) { payloadCol=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"payloadTop") ) { payloadTop=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"headerRename") ) { headerRename=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lastSourceRow") ) { lastSourceRow=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"rowPermutation") ) { rowPermutation=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colPermutation") ) { colPermutation=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"sourceInPatchCol") ) { sourceInPatchCol=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"patchInSourceCol") ) { patchInSourceCol=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"patchInSourceRow") ) { patchInSourceRow=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"rowPermutationRev") ) { rowPermutationRev=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colPermutationRev") ) { colPermutationRev=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"haveDroppedColumns") ) { haveDroppedColumns=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HighlightPatch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("source"));
	outFields->push(HX_CSTRING("patch"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("csv"));
	outFields->push(HX_CSTRING("header"));
	outFields->push(HX_CSTRING("headerPre"));
	outFields->push(HX_CSTRING("headerPost"));
	outFields->push(HX_CSTRING("headerRename"));
	outFields->push(HX_CSTRING("headerMove"));
	outFields->push(HX_CSTRING("modifier"));
	outFields->push(HX_CSTRING("currentRow"));
	outFields->push(HX_CSTRING("payloadCol"));
	outFields->push(HX_CSTRING("payloadTop"));
	outFields->push(HX_CSTRING("mods"));
	outFields->push(HX_CSTRING("cmods"));
	outFields->push(HX_CSTRING("rowInfo"));
	outFields->push(HX_CSTRING("cellInfo"));
	outFields->push(HX_CSTRING("rcOffset"));
	outFields->push(HX_CSTRING("indexes"));
	outFields->push(HX_CSTRING("sourceInPatchCol"));
	outFields->push(HX_CSTRING("patchInSourceCol"));
	outFields->push(HX_CSTRING("patchInSourceRow"));
	outFields->push(HX_CSTRING("lastSourceRow"));
	outFields->push(HX_CSTRING("actions"));
	outFields->push(HX_CSTRING("rowPermutation"));
	outFields->push(HX_CSTRING("rowPermutationRev"));
	outFields->push(HX_CSTRING("colPermutation"));
	outFields->push(HX_CSTRING("colPermutationRev"));
	outFields->push(HX_CSTRING("haveDroppedColumns"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,source),HX_CSTRING("source")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,patch),HX_CSTRING("patch")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,view),HX_CSTRING("view")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,csv),HX_CSTRING("csv")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,header),HX_CSTRING("header")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,headerPre),HX_CSTRING("headerPre")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,headerPost),HX_CSTRING("headerPost")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,headerRename),HX_CSTRING("headerRename")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,headerMove),HX_CSTRING("headerMove")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,modifier),HX_CSTRING("modifier")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,currentRow),HX_CSTRING("currentRow")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,payloadCol),HX_CSTRING("payloadCol")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,payloadTop),HX_CSTRING("payloadTop")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,mods),HX_CSTRING("mods")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,cmods),HX_CSTRING("cmods")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,rowInfo),HX_CSTRING("rowInfo")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,cellInfo),HX_CSTRING("cellInfo")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,rcOffset),HX_CSTRING("rcOffset")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,indexes),HX_CSTRING("indexes")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,sourceInPatchCol),HX_CSTRING("sourceInPatchCol")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,patchInSourceCol),HX_CSTRING("patchInSourceCol")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,patchInSourceRow),HX_CSTRING("patchInSourceRow")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,lastSourceRow),HX_CSTRING("lastSourceRow")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,actions),HX_CSTRING("actions")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,rowPermutation),HX_CSTRING("rowPermutation")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,rowPermutationRev),HX_CSTRING("rowPermutationRev")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,colPermutation),HX_CSTRING("colPermutation")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,colPermutationRev),HX_CSTRING("colPermutationRev")},
	{hx::fsObject,(int)offsetof(HighlightPatch_obj,haveDroppedColumns),HX_CSTRING("haveDroppedColumns")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("source"),
	HX_CSTRING("patch"),
	HX_CSTRING("view"),
	HX_CSTRING("csv"),
	HX_CSTRING("header"),
	HX_CSTRING("headerPre"),
	HX_CSTRING("headerPost"),
	HX_CSTRING("headerRename"),
	HX_CSTRING("headerMove"),
	HX_CSTRING("modifier"),
	HX_CSTRING("currentRow"),
	HX_CSTRING("payloadCol"),
	HX_CSTRING("payloadTop"),
	HX_CSTRING("mods"),
	HX_CSTRING("cmods"),
	HX_CSTRING("rowInfo"),
	HX_CSTRING("cellInfo"),
	HX_CSTRING("rcOffset"),
	HX_CSTRING("indexes"),
	HX_CSTRING("sourceInPatchCol"),
	HX_CSTRING("patchInSourceCol"),
	HX_CSTRING("patchInSourceRow"),
	HX_CSTRING("lastSourceRow"),
	HX_CSTRING("actions"),
	HX_CSTRING("rowPermutation"),
	HX_CSTRING("rowPermutationRev"),
	HX_CSTRING("colPermutation"),
	HX_CSTRING("colPermutationRev"),
	HX_CSTRING("haveDroppedColumns"),
	HX_CSTRING("reset"),
	HX_CSTRING("apply"),
	HX_CSTRING("needSourceColumns"),
	HX_CSTRING("needSourceIndex"),
	HX_CSTRING("applyRow"),
	HX_CSTRING("getDatum"),
	HX_CSTRING("getString"),
	HX_CSTRING("applyMeta"),
	HX_CSTRING("applyHeader"),
	HX_CSTRING("lookUp"),
	HX_CSTRING("applyAction"),
	HX_CSTRING("checkAct"),
	HX_CSTRING("getPreString"),
	HX_CSTRING("getRowString"),
	HX_CSTRING("sortMods"),
	HX_CSTRING("processMods"),
	HX_CSTRING("computeOrdering"),
	HX_CSTRING("permuteRows"),
	HX_CSTRING("finishRows"),
	HX_CSTRING("permuteColumns"),
	HX_CSTRING("finishColumns"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HighlightPatch_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HighlightPatch_obj::__mClass,"__mClass");
};

#endif

Class HighlightPatch_obj::__mClass;

void HighlightPatch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.HighlightPatch"), hx::TCanCast< HighlightPatch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void HighlightPatch_obj::__boot()
{
}

} // end namespace coopy
