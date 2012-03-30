//#pragma once
#ifndef VERBALSAINT_H
#define VERBALSAINT_H

#define VS_INNER(X)	namespace VERBALSAINT{ namespace X{
#define VS_INNER_END(X)	}}

#define VS	namespace VERBALSAINT{
#define VS_END	}

#define UVS_INNER(X)	using namespace VERBALSAINT::X;
#define UVS	using namespace VERBALSAINT;

#ifdef SUTRA
#define BUDDHA namespace { \
const char* Buddha = "一切有為法 如夢幻泡影 如露亦如電 應做如是觀"; \
const char* Sutra = "序分 正宗分 流通分"; \
}
#endif

#endif // VERBALSAINT_H
