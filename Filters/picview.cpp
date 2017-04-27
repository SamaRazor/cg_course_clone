#include "picview.h"

PicView::PicView(QWidget *parent) : QWidget(parent)
{

}

PicView::PicView(QWidget *parent, int32_t size_x, int32_t size_y) : QWidget(parent)
{
    this->setGeometry(400, 50, size_x, size_y);
    _previewImage = new QImage(QSize(size_x + 2, size_y + 2), QImage::Format_RGBA8888);
    setMouseTracking(true);
}

void PicView::paintEvent(QPaintEvent * ) {

    if (!image_loaded) {
        memset(_previewImage->bits(), 255, _previewImage->height() * _previewImage->width() * _previewImage->depth() / 8);
    }
    QPainter painter(this);
    if (image_loaded) {
        painter.drawImage(QRect(0, 0, _previewImage->size().width(), _previewImage->size().height()), *_previewImage);
    }
}

void PicView::loadImage(QImage image) {
    *_previewImage = image;
    image_loaded = true;
    this->repaint();
}