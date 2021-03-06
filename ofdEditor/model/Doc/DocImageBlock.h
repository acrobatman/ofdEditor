#ifndef DOCIMAGEBLOCK_H
#define DOCIMAGEBLOCK_H

#include "model_global.h"
#include "Doc/DocBlock.h"
#include "../Widget/imagepropertiesdialog.h"
#include <QLabel>           //存放图片的QWidget
#include <QMenu>
#include <QAction>

// 本类型用来表述文章中的图形、图片之类的
class DocBlock;
class ImagePropertiesDialog;

class MODELSHARED_EXPORT DocImageBlock
        : public QLabel
{
    Q_OBJECT

public:

    DocImageBlock(QWidget *parent = NULL);

    bool isWidthHeightRatioLocked();
    double getWidthHeightRatio();
    DocPassage *getPassage();           // 获得文章
    DocPage *getPage();                 // 获得页
    DocLayer *getLayer();               // 获得层
    DocBlock *getBlock();               //获取代理它的DocBlock
    QString getType();                  // 获得标识，来区分不同的块
    QMenu* getMenu();                   // 获得图片块的菜单成分
    QString getFileName();              // 获得图片的文件名
    void saveImage( QString filepath );  // 保存文件

    // 单位为 mm
    double getRealWidth();          // 获得图片真实大小
    double getRealHeight();         // 获得图片真实大小

public slots:
    void imagePropertiesChanged(
            double new_width,
            double new_height,
            double new_x,
            double new_y,
            bool ratio_locked);             // 修改图片属性
    void setFileName(QString fileName);     // 设置图片文件名
    void setImage(QString filePath);        // 直接使用路径设置图片
    void setImage(QPixmap & pixmap);        // 设置图片
    void setBlock(DocBlock * _block);       // 设置所属的块
    void changeImage();                     // 修改图片
    void setImageProperties();              // 设置图片属性
    void setWidthHeightRatioLocked(bool flag){this->width_height_ratio_locked = flag;}

protected:
    void focusInEvent(QFocusEvent *ev);
    void focusOutEvent(QFocusEvent *ev);

private:
    DocBlock * block;               //对代理它的DocBlock的引用
    QMenu * context_menu;           //右键菜单
    QAction * change_image;         //更改图片
    QAction * set_image_properties; //更改图片的位置和尺寸
    bool width_height_ratio_locked;
    double width_height_ratio;

    QString fileName;               // 图片的文件名       ---- uuid + 后缀名

    void initMenu();                // 初始化右键菜单

    double realWidth;               // 图片实际宽度
    double realHeight;              // 图片实际高度


signals:
    void signals_currrentImageBlock(DocImageBlock * textBlock);   //当前操作的imageBlock
};

#endif // DOCIMAGEBLOCK_H

