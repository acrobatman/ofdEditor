#ifndef COMMONDT_H
#define COMMONDT_H

// 其他数据类型
//#include "CT_DrawParam.h"
//#include "Color/CT_AxialShd.h"
//#include "Color/CT_Color.h"
//#include "Color/CT_ColorSpace.h"
//#include "Color/CT_Pattern.h"
//#include "Color/CT_RadialShd.h"

//6种基本数据类型
struct ST_Loc {

};

struct ST_Array {

};

struct ST_ID {
    unsigned long id;
};

struct ST_RefID {
    unsigned long ref_id;
};

struct ST_Pos {
    double x, y;
};

struct ST_Box {
    double start_x, start_y, delta_x, delta_y;
};


//class CT_PageArea {
//public:
//    ST_Box physical_box;
//};


//class CT_Color {
//    //属性
//    ST_Array value;
//    int index;
//    ST_RefID colorspace;
//};
#endif // COMMONDT_H