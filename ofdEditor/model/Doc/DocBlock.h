#ifndef DOCBLOCK_H
#define DOCBLOCK_H

#include "model_global.h"       // 导出lib使用
#include "Doc/DocBasicTypes.h"
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>

class DocLayer;
class QPainter;
class DocTextBlock;
class DocPage;
class DocPassage;
class DocImageBlock;

/**
 * @Author Chaoqun
 * @brief  一个块
 * @param  参数
 * @return 返回值
 * @date   2017/05/03
 */
class MODELSHARED_EXPORT DocBlock
        :public QGraphicsProxyWidget
{
    Q_OBJECT
public:
    enum { Type = UserType + 1 };
    int type() const
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return Type;
    }

    DocBlock(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);

    enum RectAdjustStatus
    {
        blockNone ,
        blockResize ,
        blockMove
    };     // 对块的大小状态进行调整

    RectAdjustStatus rectAdjust;                // 用来标识当前修改尺寸的状态
    DocLayer * getLayer(){return this->layer;}  // 获得所在的层
    DocPage * getPage();                        // 获得所在页
    DocPassage *getPassage();                   // 获得所在文章
    void paintHandle(QPainter& painter);        // 绘制负责变换的控制器
    qreal getZValue(){return this->realZValue;} // 获得当前块所在的Z值
    RectAdjustStatus currentStatus(QPointF pos);    // 鼠标所在位置可以进行什么调整

    bool isTextBlock();         // 判断是否DocBlock装的是否是DocTextBlock
    DocTextBlock *getTextBlock(); // 获得DocTextBlock
    bool isImageBlock();
    DocImageBlock *getImageBlock(); //获得DocImageBlock

public slots:           // 槽函数
    void setLayer(DocLayer * layer){this->layer = layer;}
    void resize(qreal w, qreal h);      // 继承函数
    void resize(const QSizeF &size);    // 继承函数
    void setZValue(qreal z);            // 继承该函数
    void setPos(qreal x, qreal y);      // 设置位置
    // 移动位置应该在所在的DocPage中吧……
    void remove();                      // 从场景中移除本框
    void setWidget(QWidget* widget);           // 旧的函数
    void setWidget(DocTextBlock *textBlock);   // SetWidget
    void setWidget(DocImageBlock * imageBlock);

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);                   // 用来绘制变化
    void focusInEvent (QFocusEvent *event);         // 焦点关注
    void focusOutEvent (QFocusEvent *event);        // 焦点离开

    // 用来修改鼠标
    void hoverMoveEvent (QGraphicsSceneHoverEvent *event);          // 鼠标悬浮响应
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);    // 双击恢复正常
    void mousePressEvent (QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent (QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent * event);
    void contextMenuEvent (QGraphicsSceneContextMenuEvent *event);   //　邮件菜单吧

private:

    DocBox boundary;            // 该块的外包矩形
    DocLayer * layer;           // 该块在哪一个层之中
    QSizeF blockSize;           // 用来纪录大小
    QPointF blockOldPos;        // 用来记录旧的位置

    DocTextBlock * textBlock;    // 存下引用
    DocImageBlock * imageBlock; //同上

    bool isFocused;             // 是否被聚焦
    bool blockIsResizing;       // 是否正在改变大小
    bool isInResizeArea(const QPointF& pos);    // 检查鼠标是否在重置大小区域
    qreal realZValue;           // 真实的z值

signals:
    void signals_blockRemoved(DocBlock* block);     // 当本块被移除时发出信号

};

#endif // DOCBLOCK_H
