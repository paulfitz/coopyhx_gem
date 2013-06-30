#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_coopy_Alignment
#include <coopy/Alignment.h>
#endif
#ifndef INCLUDED_coopy_Ordering
#include <coopy/Ordering.h>
#endif
#ifndef INCLUDED_coopy_Table
#include <coopy/Table.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
namespace coopy{

Void Alignment_obj::__construct()
{
HX_STACK_PUSH("Alignment::new","coopy/Alignment.hx",21);
{
	HX_STACK_LINE(22)
	this->map_a2b = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(23)
	this->map_b2a = ::haxe::ds::IntMap_obj::__new();
	HX_STACK_LINE(24)
	this->ha = this->hb = (int)0;
	HX_STACK_LINE(25)
	this->map_count = (int)0;
	HX_STACK_LINE(26)
	this->reference = null();
	HX_STACK_LINE(27)
	this->meta = null();
	HX_STACK_LINE(28)
	this->order_cache_has_reference = false;
	HX_STACK_LINE(29)
	this->ia = (int)0;
	HX_STACK_LINE(30)
	this->ib = (int)0;
}
;
	return null();
}

Alignment_obj::~Alignment_obj() { }

Dynamic Alignment_obj::__CreateEmpty() { return  new Alignment_obj; }
hx::ObjectPtr< Alignment_obj > Alignment_obj::__new()
{  hx::ObjectPtr< Alignment_obj > result = new Alignment_obj();
	result->__construct();
	return result;}

Dynamic Alignment_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Alignment_obj > result = new Alignment_obj();
	result->__construct();
	return result;}

::coopy::Ordering Alignment_obj::toOrder2( ){
	HX_STACK_PUSH("Alignment::toOrder2","coopy/Alignment.hx",284);
	HX_STACK_THIS(this);
	HX_STACK_LINE(286)
	::coopy::Ordering order = ::coopy::Ordering_obj::__new();		HX_STACK_VAR(order,"order");
	HX_STACK_LINE(287)
	int xa = (int)0;		HX_STACK_VAR(xa,"xa");
	HX_STACK_LINE(288)
	int xas = this->ha;		HX_STACK_VAR(xas,"xas");
	HX_STACK_LINE(289)
	int xb = (int)0;		HX_STACK_VAR(xb,"xb");
	HX_STACK_LINE(290)
	::haxe::ds::IntMap va = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(va,"va");
	HX_STACK_LINE(291)
	{
		HX_STACK_LINE(291)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->ha;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(291)
		while(((_g1 < _g))){
			HX_STACK_LINE(291)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(292)
			va->set(i,i);
		}
	}
	HX_STACK_LINE(294)
	while(((bool(va->keys()->__Field(HX_CSTRING("hasNext"),true)()) || bool((xb < this->hb))))){
		HX_STACK_LINE(295)
		if (((xa >= this->ha))){
			HX_STACK_LINE(295)
			xa = (int)0;
		}
		HX_STACK_LINE(297)
		if (((bool((xa < this->ha)) && bool((this->a2b(xa) == null()))))){
			HX_STACK_LINE(298)
			if ((va->exists(xa))){
				HX_STACK_LINE(300)
				order->add(xa,(int)-1,null());
				HX_STACK_LINE(301)
				va->remove(xa);
				HX_STACK_LINE(302)
				(xas)--;
			}
			HX_STACK_LINE(304)
			(xa)++;
			HX_STACK_LINE(305)
			continue;
		}
		HX_STACK_LINE(307)
		if (((xb < this->hb))){
			HX_STACK_LINE(308)
			Dynamic alt = this->b2a(xb);		HX_STACK_VAR(alt,"alt");
			HX_STACK_LINE(309)
			if (((alt != null()))){
				HX_STACK_LINE(311)
				order->add(alt,xb,null());
				HX_STACK_LINE(312)
				if ((va->exists(alt))){
					HX_STACK_LINE(313)
					va->remove(alt);
					HX_STACK_LINE(314)
					(xas)--;
				}
				HX_STACK_LINE(316)
				xa = (alt + (int)1);
			}
			else{
				HX_STACK_LINE(317)
				order->add((int)-1,xb,null());
			}
			HX_STACK_LINE(321)
			(xb)++;
			HX_STACK_LINE(322)
			continue;
		}
		HX_STACK_LINE(324)
		::haxe::Log_obj::trace(HX_CSTRING("Oops, alignment problem"),hx::SourceInfo(HX_CSTRING("Alignment.hx"),324,HX_CSTRING("coopy.Alignment"),HX_CSTRING("toOrder2")));
		HX_STACK_LINE(325)
		break;
	}
	HX_STACK_LINE(327)
	return order;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,toOrder2,return )

::coopy::Ordering Alignment_obj::toOrder3( ){
	HX_STACK_PUSH("Alignment::toOrder3","coopy/Alignment.hx",102);
	HX_STACK_THIS(this);
	HX_STACK_LINE(103)
	::coopy::Alignment ref = this->reference;		HX_STACK_VAR(ref,"ref");
	HX_STACK_LINE(104)
	if (((ref == null()))){
		HX_STACK_LINE(105)
		ref = ::coopy::Alignment_obj::__new();
		HX_STACK_LINE(106)
		ref->range(this->ha,this->ha);
		HX_STACK_LINE(107)
		ref->tables(this->ta,this->ta);
		HX_STACK_LINE(108)
		{
			HX_STACK_LINE(108)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->ha;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(108)
			while(((_g1 < _g))){
				HX_STACK_LINE(108)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(109)
				ref->link(i,i);
			}
		}
	}
	HX_STACK_LINE(112)
	::coopy::Ordering order = ::coopy::Ordering_obj::__new();		HX_STACK_VAR(order,"order");
	HX_STACK_LINE(113)
	if (((this->reference == null()))){
		HX_STACK_LINE(113)
		order->ignoreParent();
	}
	HX_STACK_LINE(116)
	int xp = (int)0;		HX_STACK_VAR(xp,"xp");
	HX_STACK_LINE(117)
	int xl = (int)0;		HX_STACK_VAR(xl,"xl");
	HX_STACK_LINE(118)
	int xr = (int)0;		HX_STACK_VAR(xr,"xr");
	HX_STACK_LINE(119)
	int hp = this->ha;		HX_STACK_VAR(hp,"hp");
	HX_STACK_LINE(120)
	int hl = ref->hb;		HX_STACK_VAR(hl,"hl");
	HX_STACK_LINE(121)
	int hr = this->hb;		HX_STACK_VAR(hr,"hr");
	HX_STACK_LINE(122)
	::haxe::ds::IntMap vp = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(vp,"vp");
	HX_STACK_LINE(123)
	::haxe::ds::IntMap vl = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(vl,"vl");
	HX_STACK_LINE(124)
	::haxe::ds::IntMap vr = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(vr,"vr");
	HX_STACK_LINE(125)
	{
		HX_STACK_LINE(125)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(125)
		while(((_g < hp))){
			HX_STACK_LINE(125)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(125)
			vp->set(i,i);
		}
	}
	HX_STACK_LINE(126)
	{
		HX_STACK_LINE(126)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(126)
		while(((_g < hl))){
			HX_STACK_LINE(126)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(126)
			vl->set(i,i);
		}
	}
	HX_STACK_LINE(127)
	{
		HX_STACK_LINE(127)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(127)
		while(((_g < hr))){
			HX_STACK_LINE(127)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(127)
			vr->set(i,i);
		}
	}
	HX_STACK_LINE(128)
	int ct_vp = hp;		HX_STACK_VAR(ct_vp,"ct_vp");
	HX_STACK_LINE(129)
	int ct_vl = hl;		HX_STACK_VAR(ct_vl,"ct_vl");
	HX_STACK_LINE(130)
	int ct_vr = hr;		HX_STACK_VAR(ct_vr,"ct_vr");
	HX_STACK_LINE(131)
	int prev = (int)-1;		HX_STACK_VAR(prev,"prev");
	HX_STACK_LINE(132)
	int ct = (int)0;		HX_STACK_VAR(ct,"ct");
	HX_STACK_LINE(133)
	int max_ct = ((((hp + hl) + hr)) * (int)10);		HX_STACK_VAR(max_ct,"max_ct");
	HX_STACK_LINE(134)
	while(((bool((bool((ct_vp > (int)0)) || bool((ct_vl > (int)0)))) || bool((ct_vr > (int)0))))){
		HX_STACK_LINE(137)
		(ct)++;
		HX_STACK_LINE(138)
		if (((ct > max_ct))){
			HX_STACK_LINE(139)
			::haxe::Log_obj::trace(HX_CSTRING("Ordering took too long, something went wrong"),hx::SourceInfo(HX_CSTRING("Alignment.hx"),139,HX_CSTRING("coopy.Alignment"),HX_CSTRING("toOrder3")));
			HX_STACK_LINE(140)
			break;
		}
		HX_STACK_LINE(142)
		if (((xp >= hp))){
			HX_STACK_LINE(142)
			xp = (int)0;
		}
		HX_STACK_LINE(143)
		if (((xl >= hl))){
			HX_STACK_LINE(143)
			xl = (int)0;
		}
		HX_STACK_LINE(144)
		if (((xr >= hr))){
			HX_STACK_LINE(144)
			xr = (int)0;
		}
		HX_STACK_LINE(148)
		if (((bool((xp < hp)) && bool((ct_vp > (int)0))))){
			HX_STACK_LINE(148)
			if (((bool((this->a2b(xp) == null())) && bool((ref->a2b(xp) == null()))))){
				HX_STACK_LINE(151)
				if ((vp->exists(xp))){
					HX_STACK_LINE(153)
					order->add((int)-1,(int)-1,xp);
					HX_STACK_LINE(154)
					prev = xp;
					HX_STACK_LINE(155)
					vp->remove(xp);
					HX_STACK_LINE(156)
					(ct_vp)--;
				}
				HX_STACK_LINE(158)
				(xp)++;
				HX_STACK_LINE(159)
				continue;
			}
		}
		HX_STACK_LINE(162)
		Dynamic zl = null();		HX_STACK_VAR(zl,"zl");
		HX_STACK_LINE(163)
		Dynamic zr = null();		HX_STACK_VAR(zr,"zr");
		HX_STACK_LINE(164)
		if (((bool((xl < hl)) && bool((ct_vl > (int)0))))){
			HX_STACK_LINE(165)
			zl = ref->b2a(xl);
			HX_STACK_LINE(166)
			if (((zl == null()))){
				HX_STACK_LINE(167)
				if ((vl->exists(xl))){
					HX_STACK_LINE(169)
					order->add(xl,(int)-1,(int)-1);
					HX_STACK_LINE(171)
					vl->remove(xl);
					HX_STACK_LINE(172)
					(ct_vl)--;
				}
				HX_STACK_LINE(174)
				(xl)++;
				HX_STACK_LINE(175)
				continue;
			}
		}
		HX_STACK_LINE(178)
		if (((bool((xr < hr)) && bool((ct_vr > (int)0))))){
			HX_STACK_LINE(179)
			zr = this->b2a(xr);
			HX_STACK_LINE(180)
			if (((zr == null()))){
				HX_STACK_LINE(181)
				if ((vr->exists(xr))){
					HX_STACK_LINE(183)
					order->add((int)-1,xr,(int)-1);
					HX_STACK_LINE(185)
					vr->remove(xr);
					HX_STACK_LINE(186)
					(ct_vr)--;
				}
				HX_STACK_LINE(188)
				(xr)++;
				HX_STACK_LINE(189)
				continue;
			}
		}
		HX_STACK_LINE(192)
		if (((zl != null()))){
			HX_STACK_LINE(192)
			if (((this->a2b(zl) == null()))){
				HX_STACK_LINE(195)
				if ((vl->exists(xl))){
					HX_STACK_LINE(197)
					order->add(xl,(int)-1,zl);
					HX_STACK_LINE(198)
					prev = zl;
					HX_STACK_LINE(199)
					vp->remove(zl);
					HX_STACK_LINE(200)
					(ct_vp)--;
					HX_STACK_LINE(201)
					vl->remove(xl);
					HX_STACK_LINE(202)
					(ct_vl)--;
					HX_STACK_LINE(203)
					xp = (zl + (int)1);
				}
				HX_STACK_LINE(205)
				(xl)++;
				HX_STACK_LINE(206)
				continue;
			}
		}
		HX_STACK_LINE(209)
		if (((zr != null()))){
			HX_STACK_LINE(209)
			if (((ref->a2b(zr) == null()))){
				HX_STACK_LINE(212)
				if ((vr->exists(xr))){
					HX_STACK_LINE(214)
					order->add((int)-1,xr,zr);
					HX_STACK_LINE(215)
					prev = zr;
					HX_STACK_LINE(216)
					vp->remove(zr);
					HX_STACK_LINE(217)
					(ct_vp)--;
					HX_STACK_LINE(218)
					vr->remove(xr);
					HX_STACK_LINE(219)
					(ct_vr)--;
					HX_STACK_LINE(220)
					xp = (zr + (int)1);
				}
				HX_STACK_LINE(222)
				(xr)++;
				HX_STACK_LINE(223)
				continue;
			}
		}
		HX_STACK_LINE(232)
		if (((bool((bool((bool((zl != null())) && bool((zr != null())))) && bool((this->a2b(zl) != null())))) && bool((ref->a2b(zr) != null()))))){
			HX_STACK_LINE(233)
			if (((zl == (prev + (int)1)))){
				HX_STACK_LINE(240)
				if ((vr->exists(xr))){
					HX_STACK_LINE(242)
					order->add(ref->a2b(zr),xr,zr);
					HX_STACK_LINE(243)
					prev = zr;
					HX_STACK_LINE(244)
					vp->remove(zr);
					HX_STACK_LINE(245)
					(ct_vp)--;
					HX_STACK_LINE(246)
					vl->remove(ref->a2b(zr));
					HX_STACK_LINE(247)
					(ct_vl)--;
					HX_STACK_LINE(248)
					vr->remove(xr);
					HX_STACK_LINE(249)
					(ct_vr)--;
					HX_STACK_LINE(250)
					xp = (zr + (int)1);
					HX_STACK_LINE(251)
					xl = (ref->a2b(zr) + (int)1);
				}
				HX_STACK_LINE(253)
				(xr)++;
				HX_STACK_LINE(254)
				continue;
			}
			else{
				HX_STACK_LINE(257)
				if ((vl->exists(xl))){
					HX_STACK_LINE(259)
					order->add(xl,this->a2b(zl),zl);
					HX_STACK_LINE(260)
					prev = zl;
					HX_STACK_LINE(261)
					vp->remove(zl);
					HX_STACK_LINE(262)
					(ct_vp)--;
					HX_STACK_LINE(263)
					vl->remove(xl);
					HX_STACK_LINE(264)
					(ct_vl)--;
					HX_STACK_LINE(265)
					vr->remove(this->a2b(zl));
					HX_STACK_LINE(266)
					(ct_vr)--;
					HX_STACK_LINE(267)
					xp = (zl + (int)1);
					HX_STACK_LINE(268)
					xr = (this->a2b(zl) + (int)1);
				}
				HX_STACK_LINE(270)
				(xl)++;
				HX_STACK_LINE(271)
				continue;
			}
		}
		HX_STACK_LINE(274)
		(xp)++;
		HX_STACK_LINE(275)
		(xl)++;
		HX_STACK_LINE(276)
		(xr)++;
	}
	HX_STACK_LINE(279)
	return order;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,toOrder3,return )

int Alignment_obj::getTargetHeader( ){
	HX_STACK_PUSH("Alignment::getTargetHeader","coopy/Alignment.hx",98);
	HX_STACK_THIS(this);
	HX_STACK_LINE(98)
	return this->ib;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,getTargetHeader,return )

int Alignment_obj::getSourceHeader( ){
	HX_STACK_PUSH("Alignment::getSourceHeader","coopy/Alignment.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_LINE(94)
	return this->ia;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,getSourceHeader,return )

::coopy::Table Alignment_obj::getTarget( ){
	HX_STACK_PUSH("Alignment::getTarget","coopy/Alignment.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_LINE(90)
	return this->tb;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,getTarget,return )

::coopy::Table Alignment_obj::getSource( ){
	HX_STACK_PUSH("Alignment::getSource","coopy/Alignment.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_LINE(86)
	return this->ta;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,getSource,return )

::coopy::Ordering Alignment_obj::toOrder( ){
	HX_STACK_PUSH("Alignment::toOrder","coopy/Alignment.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_LINE(74)
	if (((this->order_cache != null()))){
		HX_STACK_LINE(74)
		if (((this->reference != null()))){
			HX_STACK_LINE(75)
			if ((!(this->order_cache_has_reference))){
				HX_STACK_LINE(76)
				this->order_cache = null();
			}
		}
	}
	HX_STACK_LINE(81)
	if (((this->order_cache == null()))){
		HX_STACK_LINE(81)
		this->order_cache = this->toOrder3();
	}
	HX_STACK_LINE(82)
	if (((this->reference != null()))){
		HX_STACK_LINE(82)
		this->order_cache_has_reference = true;
	}
	HX_STACK_LINE(83)
	return this->order_cache;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,toOrder,return )

::String Alignment_obj::toString( ){
	HX_STACK_PUSH("Alignment::toString","coopy/Alignment.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_LINE(69)
	return (HX_CSTRING("") + this->map_a2b->toString());
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,toString,return )

int Alignment_obj::count( ){
	HX_STACK_PUSH("Alignment::count","coopy/Alignment.hx",65);
	HX_STACK_THIS(this);
	HX_STACK_LINE(65)
	return this->map_count;
}


HX_DEFINE_DYNAMIC_FUNC0(Alignment_obj,count,return )

Dynamic Alignment_obj::b2a( int b){
	HX_STACK_PUSH("Alignment::b2a","coopy/Alignment.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(61)
	return this->map_b2a->get(b);
}


HX_DEFINE_DYNAMIC_FUNC1(Alignment_obj,b2a,return )

Dynamic Alignment_obj::a2b( int a){
	HX_STACK_PUSH("Alignment::a2b","coopy/Alignment.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_LINE(57)
	return this->map_a2b->get(a);
}


HX_DEFINE_DYNAMIC_FUNC1(Alignment_obj,a2b,return )

Void Alignment_obj::link( int a,int b){
{
		HX_STACK_PUSH("Alignment::link","coopy/Alignment.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_ARG(a,"a");
		HX_STACK_ARG(b,"b");
		HX_STACK_LINE(52)
		this->map_a2b->set(a,b);
		HX_STACK_LINE(53)
		this->map_b2a->set(b,a);
		HX_STACK_LINE(54)
		(this->map_count)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Alignment_obj,link,(void))

Void Alignment_obj::setRowlike( bool flag){
{
		HX_STACK_PUSH("Alignment::setRowlike","coopy/Alignment.hx",48);
		HX_STACK_THIS(this);
		HX_STACK_ARG(flag,"flag");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Alignment_obj,setRowlike,(void))

Void Alignment_obj::headers( int ia,int ib){
{
		HX_STACK_PUSH("Alignment::headers","coopy/Alignment.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ia,"ia");
		HX_STACK_ARG(ib,"ib");
		HX_STACK_LINE(44)
		this->ia = ia;
		HX_STACK_LINE(45)
		this->ib = ib;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Alignment_obj,headers,(void))

Void Alignment_obj::tables( ::coopy::Table ta,::coopy::Table tb){
{
		HX_STACK_PUSH("Alignment::tables","coopy/Alignment.hx",38);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ta,"ta");
		HX_STACK_ARG(tb,"tb");
		HX_STACK_LINE(39)
		this->ta = ta;
		HX_STACK_LINE(40)
		this->tb = tb;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Alignment_obj,tables,(void))

Void Alignment_obj::range( int ha,int hb){
{
		HX_STACK_PUSH("Alignment::range","coopy/Alignment.hx",33);
		HX_STACK_THIS(this);
		HX_STACK_ARG(ha,"ha");
		HX_STACK_ARG(hb,"hb");
		HX_STACK_LINE(34)
		this->ha = ha;
		HX_STACK_LINE(35)
		this->hb = hb;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Alignment_obj,range,(void))


Alignment_obj::Alignment_obj()
{
}

void Alignment_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Alignment);
	HX_MARK_MEMBER_NAME(meta,"meta");
	HX_MARK_MEMBER_NAME(reference,"reference");
	HX_MARK_MEMBER_NAME(order_cache_has_reference,"order_cache_has_reference");
	HX_MARK_MEMBER_NAME(order_cache,"order_cache");
	HX_MARK_MEMBER_NAME(map_count,"map_count");
	HX_MARK_MEMBER_NAME(ib,"ib");
	HX_MARK_MEMBER_NAME(ia,"ia");
	HX_MARK_MEMBER_NAME(tb,"tb");
	HX_MARK_MEMBER_NAME(ta,"ta");
	HX_MARK_MEMBER_NAME(hb,"hb");
	HX_MARK_MEMBER_NAME(ha,"ha");
	HX_MARK_MEMBER_NAME(map_b2a,"map_b2a");
	HX_MARK_MEMBER_NAME(map_a2b,"map_a2b");
	HX_MARK_END_CLASS();
}

void Alignment_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(meta,"meta");
	HX_VISIT_MEMBER_NAME(reference,"reference");
	HX_VISIT_MEMBER_NAME(order_cache_has_reference,"order_cache_has_reference");
	HX_VISIT_MEMBER_NAME(order_cache,"order_cache");
	HX_VISIT_MEMBER_NAME(map_count,"map_count");
	HX_VISIT_MEMBER_NAME(ib,"ib");
	HX_VISIT_MEMBER_NAME(ia,"ia");
	HX_VISIT_MEMBER_NAME(tb,"tb");
	HX_VISIT_MEMBER_NAME(ta,"ta");
	HX_VISIT_MEMBER_NAME(hb,"hb");
	HX_VISIT_MEMBER_NAME(ha,"ha");
	HX_VISIT_MEMBER_NAME(map_b2a,"map_b2a");
	HX_VISIT_MEMBER_NAME(map_a2b,"map_a2b");
}

Dynamic Alignment_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ib") ) { return ib; }
		if (HX_FIELD_EQ(inName,"ia") ) { return ia; }
		if (HX_FIELD_EQ(inName,"tb") ) { return tb; }
		if (HX_FIELD_EQ(inName,"ta") ) { return ta; }
		if (HX_FIELD_EQ(inName,"hb") ) { return hb; }
		if (HX_FIELD_EQ(inName,"ha") ) { return ha; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"b2a") ) { return b2a_dyn(); }
		if (HX_FIELD_EQ(inName,"a2b") ) { return a2b_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"link") ) { return link_dyn(); }
		if (HX_FIELD_EQ(inName,"meta") ) { return meta; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return count_dyn(); }
		if (HX_FIELD_EQ(inName,"range") ) { return range_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"tables") ) { return tables_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"toOrder") ) { return toOrder_dyn(); }
		if (HX_FIELD_EQ(inName,"headers") ) { return headers_dyn(); }
		if (HX_FIELD_EQ(inName,"map_b2a") ) { return map_b2a; }
		if (HX_FIELD_EQ(inName,"map_a2b") ) { return map_a2b; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toOrder2") ) { return toOrder2_dyn(); }
		if (HX_FIELD_EQ(inName,"toOrder3") ) { return toOrder3_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getTarget") ) { return getTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"getSource") ) { return getSource_dyn(); }
		if (HX_FIELD_EQ(inName,"reference") ) { return reference; }
		if (HX_FIELD_EQ(inName,"map_count") ) { return map_count; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setRowlike") ) { return setRowlike_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"order_cache") ) { return order_cache; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getTargetHeader") ) { return getTargetHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"getSourceHeader") ) { return getSourceHeader_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"order_cache_has_reference") ) { return order_cache_has_reference; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Alignment_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ib") ) { ib=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ia") ) { ia=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tb") ) { tb=inValue.Cast< ::coopy::Table >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ta") ) { ta=inValue.Cast< ::coopy::Table >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hb") ) { hb=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ha") ) { ha=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"meta") ) { meta=inValue.Cast< ::coopy::Alignment >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"map_b2a") ) { map_b2a=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"map_a2b") ) { map_a2b=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"reference") ) { reference=inValue.Cast< ::coopy::Alignment >(); return inValue; }
		if (HX_FIELD_EQ(inName,"map_count") ) { map_count=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"order_cache") ) { order_cache=inValue.Cast< ::coopy::Ordering >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"order_cache_has_reference") ) { order_cache_has_reference=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Alignment_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("meta"));
	outFields->push(HX_CSTRING("reference"));
	outFields->push(HX_CSTRING("order_cache_has_reference"));
	outFields->push(HX_CSTRING("order_cache"));
	outFields->push(HX_CSTRING("map_count"));
	outFields->push(HX_CSTRING("ib"));
	outFields->push(HX_CSTRING("ia"));
	outFields->push(HX_CSTRING("tb"));
	outFields->push(HX_CSTRING("ta"));
	outFields->push(HX_CSTRING("hb"));
	outFields->push(HX_CSTRING("ha"));
	outFields->push(HX_CSTRING("map_b2a"));
	outFields->push(HX_CSTRING("map_a2b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toOrder2"),
	HX_CSTRING("toOrder3"),
	HX_CSTRING("getTargetHeader"),
	HX_CSTRING("getSourceHeader"),
	HX_CSTRING("getTarget"),
	HX_CSTRING("getSource"),
	HX_CSTRING("toOrder"),
	HX_CSTRING("toString"),
	HX_CSTRING("count"),
	HX_CSTRING("b2a"),
	HX_CSTRING("a2b"),
	HX_CSTRING("link"),
	HX_CSTRING("setRowlike"),
	HX_CSTRING("headers"),
	HX_CSTRING("tables"),
	HX_CSTRING("range"),
	HX_CSTRING("meta"),
	HX_CSTRING("reference"),
	HX_CSTRING("order_cache_has_reference"),
	HX_CSTRING("order_cache"),
	HX_CSTRING("map_count"),
	HX_CSTRING("ib"),
	HX_CSTRING("ia"),
	HX_CSTRING("tb"),
	HX_CSTRING("ta"),
	HX_CSTRING("hb"),
	HX_CSTRING("ha"),
	HX_CSTRING("map_b2a"),
	HX_CSTRING("map_a2b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Alignment_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Alignment_obj::__mClass,"__mClass");
};

Class Alignment_obj::__mClass;

void Alignment_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("coopy.Alignment"), hx::TCanCast< Alignment_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Alignment_obj::__boot()
{
}

} // end namespace coopy
