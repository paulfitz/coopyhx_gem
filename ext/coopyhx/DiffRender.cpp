#include <hxcpp.h>

#ifndef INCLUDED_coopy_Datum
#include <coopy/Datum.h>
#endif
#ifndef INCLUDED_coopy_DiffRender
#include <coopy/DiffRender.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_coopy_View
#include <coopy/View.h>
#endif
namespace coopy{

Void DiffRender_obj::__construct()
{
HX_STACK_PUSH("DiffRender::new","coopy/DiffRender.hx",13);
{
	HX_STACK_LINE(14)
	this->text_to_insert = Array_obj< ::String >::__new();
	HX_STACK_LINE(15)
	this->open = false;
}
;
	return null();
}

DiffRender_obj::~DiffRender_obj() { }

Dynamic DiffRender_obj::__CreateEmpty() { return  new DiffRender_obj; }
hx::ObjectPtr< DiffRender_obj > DiffRender_obj::__new()
{  hx::ObjectPtr< DiffRender_obj > result = new DiffRender_obj();
	result->__construct();
	return result;}

Dynamic DiffRender_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DiffRender_obj > result = new DiffRender_obj();
	result->__construct();
	return result;}

Void DiffRender_obj::render( ::coopy::Table rows){
{
		HX_STACK_PUSH("DiffRender::render","coopy/DiffRender.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rows,"rows");
		HX_STACK_LINE(87)
		::coopy::DiffRender render = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(render,"render");
		HX_STACK_LINE(88)
		render->beginTable();
		HX_STACK_LINE(89)
		int change_row = (int)-1;		HX_STACK_VAR(change_row,"change_row");
		HX_STACK_LINE(90)
		::coopy::View v = rows->getCellView();		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(91)
		{
			HX_STACK_LINE(91)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = rows->__Field(HX_CSTRING("get_height"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(91)
			while(((_g1 < _g))){
				HX_STACK_LINE(91)
				int row = (_g1)++;		HX_STACK_VAR(row,"row");
				HX_STACK_LINE(93)
				::String row_mode = HX_CSTRING("");		HX_STACK_VAR(row_mode,"row_mode");
				HX_STACK_LINE(94)
				::String txt = HX_CSTRING("");		HX_STACK_VAR(txt,"txt");
				HX_STACK_LINE(95)
				bool open = false;		HX_STACK_VAR(open,"open");
				HX_STACK_LINE(96)
				if (((rows->__Field(HX_CSTRING("get_width"),true)() > (int)0))){
					HX_STACK_LINE(97)
					txt = v->toString(rows->getCell((int)0,row));
					HX_STACK_LINE(98)
					if (((bool((txt == HX_CSTRING("@"))) || bool((txt == HX_CSTRING("@@")))))){
						HX_STACK_LINE(98)
						row_mode = HX_CSTRING("@@");
					}
					else{
						HX_STACK_LINE(100)
						if (((bool((bool((bool((txt == HX_CSTRING("!"))) || bool((txt == HX_CSTRING("+++"))))) || bool((txt == HX_CSTRING("---"))))) || bool((txt == HX_CSTRING("...")))))){
							HX_STACK_LINE(101)
							row_mode = txt;
							HX_STACK_LINE(102)
							if (((txt == HX_CSTRING("!")))){
								HX_STACK_LINE(102)
								change_row = row;
							}
						}
						else{
							HX_STACK_LINE(103)
							if (((txt.indexOf(HX_CSTRING("->"),null()) >= (int)0))){
								HX_STACK_LINE(103)
								row_mode = HX_CSTRING("->");
							}
							else{
								HX_STACK_LINE(105)
								open = true;
							}
						}
					}
				}
				HX_STACK_LINE(109)
				::String cmd = txt;		HX_STACK_VAR(cmd,"cmd");
				HX_STACK_LINE(110)
				render->beginRow(row_mode);
				HX_STACK_LINE(111)
				{
					HX_STACK_LINE(111)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					int _g2 = rows->__Field(HX_CSTRING("get_width"),true)();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(111)
					while(((_g3 < _g2))){
						HX_STACK_LINE(111)
						int c = (_g3)++;		HX_STACK_VAR(c,"c");
						HX_STACK_LINE(112)
						txt = v->toString(rows->getCell(c,row));
						HX_STACK_LINE(113)
						if (((txt == HX_CSTRING("NULL")))){
							HX_STACK_LINE(113)
							txt = HX_CSTRING("");
						}
						HX_STACK_LINE(114)
						if (((txt == HX_CSTRING("null")))){
							HX_STACK_LINE(114)
							txt = HX_CSTRING("");
						}
						HX_STACK_LINE(115)
						::String cell_mode = HX_CSTRING("");		HX_STACK_VAR(cell_mode,"cell_mode");
						HX_STACK_LINE(116)
						::String separator = HX_CSTRING("");		HX_STACK_VAR(separator,"separator");
						HX_STACK_LINE(117)
						if (((bool(open) && bool((change_row >= (int)0))))){
							HX_STACK_LINE(118)
							::String change = v->toString(rows->getCell(c,change_row));		HX_STACK_VAR(change,"change");
							HX_STACK_LINE(119)
							if (((bool((change == HX_CSTRING("+++"))) || bool((change == HX_CSTRING("---")))))){
								HX_STACK_LINE(119)
								cell_mode = change;
							}
						}
						HX_STACK_LINE(124)
						if (((cmd.indexOf(HX_CSTRING("->"),null()) >= (int)0))){
							HX_STACK_LINE(124)
							if (((txt.indexOf(cmd,null()) >= (int)0))){
								HX_STACK_LINE(126)
								cell_mode = HX_CSTRING("->");
								HX_STACK_LINE(127)
								separator = cmd;
							}
						}
						HX_STACK_LINE(130)
						render->insertCell(txt,cell_mode,separator);
					}
				}
				HX_STACK_LINE(132)
				render->endRow();
			}
		}
		HX_STACK_LINE(134)
		render->endTable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DiffRender_obj,render,(void))

::String DiffRender_obj::toString( ){
	HX_STACK_PUSH("DiffRender::toString","coopy/DiffRender.hx",81);
	HX_STACK_THIS(this);
	HX_STACK_LINE(81)
	return this->html();
}


HX_DEFINE_DYNAMIC_FUNC0(DiffRender_obj,toString,return )

::String DiffRender_obj::html( ){
	HX_STACK_PUSH("DiffRender::html","coopy/DiffRender.hx",77);
	HX_STACK_THIS(this);
	HX_STACK_LINE(77)
	return this->text_to_insert->join(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(DiffRender_obj,html,return )

Void DiffRender_obj::endTable( ){
{
		HX_STACK_PUSH("DiffRender::endTable","coopy/DiffRender.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_LINE(73)
		this->insert(HX_CSTRING("</table>\n"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DiffRender_obj,endTable,(void))

Void DiffRender_obj::endRow( ){
{
		HX_STACK_PUSH("DiffRender::endRow","coopy/DiffRender.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_LINE(69)
		this->insert(HX_CSTRING("</tr>\n"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DiffRender_obj,endRow,(void))

Void DiffRender_obj::insertCell( ::String txt,::String mode,::String separator){
{
		HX_STACK_PUSH("DiffRender::insertCell","coopy/DiffRender.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_ARG(txt,"txt");
		HX_STACK_ARG(mode,"mode");
		HX_STACK_ARG(separator,"separator");
		HX_STACK_LINE(55)
		::String cell_decorate = HX_CSTRING("");		HX_STACK_VAR(cell_decorate,"cell_decorate");
		HX_STACK_LINE(56)
		::String _switch_1 = (mode);
		if (  ( _switch_1==HX_CSTRING("+++"))){
			HX_STACK_LINE(57)
			hx::AddEq(cell_decorate,HX_CSTRING(" class=\"add\""));
		}
		else if (  ( _switch_1==HX_CSTRING("---"))){
			HX_STACK_LINE(59)
			hx::AddEq(cell_decorate,HX_CSTRING(" class=\"remove\""));
		}
		else if (  ( _switch_1==HX_CSTRING("->"))){
			HX_STACK_LINE(61)
			hx::AddEq(cell_decorate,HX_CSTRING(" class=\"modify\""));
		}
		HX_STACK_LINE(64)
		this->insert(((this->td_open + cell_decorate) + HX_CSTRING(">")));
		HX_STACK_LINE(65)
		this->insert(txt);
		HX_STACK_LINE(66)
		this->insert(this->td_close);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(DiffRender_obj,insertCell,(void))

Void DiffRender_obj::beginRow( ::String mode){
{
		HX_STACK_PUSH("DiffRender::beginRow","coopy/DiffRender.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mode,"mode");
		HX_STACK_LINE(27)
		this->td_open = HX_CSTRING("<td");
		HX_STACK_LINE(28)
		this->td_close = HX_CSTRING("</td>");
		HX_STACK_LINE(29)
		this->row_color = HX_CSTRING("");
		HX_STACK_LINE(30)
		this->open = false;
		HX_STACK_LINE(31)
		::String _switch_2 = (mode);
		if (  ( _switch_2==HX_CSTRING("@@"))){
			HX_STACK_LINE(33)
			this->td_open = HX_CSTRING("<th");
			HX_STACK_LINE(34)
			this->td_close = HX_CSTRING("</th>");
		}
		else if (  ( _switch_2==HX_CSTRING("!"))){
			HX_STACK_LINE(35)
			this->row_color = HX_CSTRING("spec");
		}
		else if (  ( _switch_2==HX_CSTRING("+++"))){
			HX_STACK_LINE(37)
			this->row_color = HX_CSTRING("add");
		}
		else if (  ( _switch_2==HX_CSTRING("---"))){
			HX_STACK_LINE(39)
			this->row_color = HX_CSTRING("remove");
		}
		else  {
			HX_STACK_LINE(41)
			this->open = true;
		}
;
;
		HX_STACK_LINE(44)
		::String tr = HX_CSTRING("<tr>");		HX_STACK_VAR(tr,"tr");
		HX_STACK_LINE(45)
		::String row_decorate = HX_CSTRING("");		HX_STACK_VAR(row_decorate,"row_decorate");
		HX_STACK_LINE(46)
		if (((this->row_color != HX_CSTRING("")))){
			HX_STACK_LINE(47)
			row_decorate = ((HX_CSTRING(" class=\"") + this->row_color) + HX_CSTRING("\""));
			HX_STACK_LINE(48)
			tr = ((HX_CSTRING("<tr") + row_decorate) + HX_CSTRING(">"));
		}
		HX_STACK_LINE(50)
		this->insert(tr);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DiffRender_obj,beginRow,(void))

Void DiffRender_obj::beginTable( ){
{
		HX_STACK_PUSH("DiffRender::beginTable","coopy/DiffRender.hx",22);
		HX_STACK_THIS(this);
		HX_STACK_LINE(22)
		this->insert(HX_CSTRING("<table>\n"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(DiffRender_obj,beginTable,(void))

Void DiffRender_obj::insert( ::String str){
{
		HX_STACK_PUSH("DiffRender::insert","coopy/DiffRender.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_ARG(str,"str");
		HX_STACK_LINE(18)
		this->text_to_insert->push(str);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DiffRender_obj,insert,(void))


DiffRender_obj::DiffRender_obj()
{
}

void DiffRender_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DiffRender);
	HX_MARK_MEMBER_NAME(open,"open");
	HX_MARK_MEMBER_NAME(row_color,"row_color");
	HX_MARK_MEMBER_NAME(td_close,"td_close");
	HX_MARK_MEMBER_NAME(td_open,"td_open");
	HX_MARK_MEMBER_NAME(text_to_insert,"text_to_insert");
	HX_MARK_END_CLASS();
}

void DiffRender_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(open,"open");
	HX_VISIT_MEMBER_NAME(row_color,"row_color");
	HX_VISIT_MEMBER_NAME(td_close,"td_close");
	HX_VISIT_MEMBER_NAME(td_open,"td_open");
	HX_VISIT_MEMBER_NAME(text_to_insert,"text_to_insert");
}

Dynamic DiffRender_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"html") ) { return html_dyn(); }
		if (HX_FIELD_EQ(inName,"open") ) { return open; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"endRow") ) { return endRow_dyn(); }
		if (HX_FIELD_EQ(inName,"insert") ) { return insert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"td_open") ) { return td_open; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"endTable") ) { return endTable_dyn(); }
		if (HX_FIELD_EQ(inName,"beginRow") ) { return beginRow_dyn(); }
		if (HX_FIELD_EQ(inName,"td_close") ) { return td_close; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"row_color") ) { return row_color; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"insertCell") ) { return insertCell_dyn(); }
		if (HX_FIELD_EQ(inName,"beginTable") ) { return beginTable_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"text_to_insert") ) { return text_to_insert; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DiffRender_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"open") ) { open=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"td_open") ) { td_open=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"td_close") ) { td_close=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"row_color") ) { row_color=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"text_to_insert") ) { text_to_insert=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DiffRender_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("open"));
	outFields->push(HX_CSTRING("row_color"));
	outFields->push(HX_CSTRING("td_close"));
	outFields->push(HX_CSTRING("td_open"));
	outFields->push(HX_CSTRING("text_to_insert"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	HX_CSTRING("toString"),
	HX_CSTRING("html"),
	HX_CSTRING("endTable"),
	HX_CSTRING("endRow"),
	HX_CSTRING("insertCell"),
	HX_CSTRING("beginRow"),
	HX_CSTRING("beginTable"),
	HX_CSTRING("insert"),
	HX_CSTRING("open"),
	HX_CSTRING("row_color"),
	HX_CSTRING("td_close"),
	HX_CSTRING("td_open"),
	HX_CSTRING("text_to_insert"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DiffRender_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DiffRender_obj::__mClass,"__mClass");
};

Class DiffRender_obj::__mClass;

void DiffRender_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.DiffRender"), hx::TCanCast< DiffRender_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DiffRender_obj::__boot()
{
}

} // end namespace coopy
