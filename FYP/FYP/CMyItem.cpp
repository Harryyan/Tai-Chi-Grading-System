#include "CMyItem.h"

CMyItem::CMyItem(qreal x, qreal y ) : QGraphicsItem(){
	setPos( x, y );  
}

QRectF CMyItem::boundingRect() const{
	return QRectF(-6, -13, 13, 18);
}

void CMyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	 //绘制电台图标，必须小于边框矩形  
	 painter->setRenderHint( QPainter::Antialiasing );  
	 painter->setPen( QPen( Qt::red, 2 ) );  
	 beforePaint(painter);
}

void CMyItem::beforePaint(QPainter *painter){
	 //Draw the coordinate
	 painter->drawLine(-150,0,150,0);
	 painter->drawLine(0,200,0,-200);

	 painter->setPen( QPen( Qt::blue, 2 ) );
	 painter->drawLine(-30,70,0,20);
	 painter->drawLine(0,20,10,-40);
	 painter->drawLine(10,-40,30,-90);

	 painter->setPen( QPen( Qt::red, 2 ) );
	 painter->drawText(144,4,">");
	 painter->rotate(90);
	 painter->drawText(190,4,">");

	 painter->rotate(270);
}