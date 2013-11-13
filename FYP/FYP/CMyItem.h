#ifndef CMYITEM_H
#define CMYITEM_H

#include <QtGui/QtGui>

class CMyItem : public QGraphicsItem
{
public:
	CMyItem(qreal, qreal );
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	
private:
	void beforePaint(QPainter *painter);
};

#endif