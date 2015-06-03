/********************************************************************************
** Form generated from reading UI file 'tradesimulator.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADESIMULATOR_H
#define UI_TRADESIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TradeSimulator
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *LeftPanel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QGraphicsView *tradeSimulator_graphicsGraphDisplay;
    QTableWidget *tradeSimulator_returnsAnalysis;
    QWidget *widget;
    QVBoxLayout *RightPanel;
    QSpacerItem *logoVerticalSpacer;
    QWidget *horizontalWidget;
    QHBoxLayout *logoLayout;
    QLabel *logo;
    QLabel *companylabel;
    QWidget *verticalWidget;
    QVBoxLayout *SummaryLayout;
    QWidget *horizontalWidget1;
    QHBoxLayout *equityLine;
    QLabel *equity;
    QLabel *tradeSimulator_companyName;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *equity_2;
    QLabel *tradeSimulator_ongoingReturns;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QWidget *horizontalWidget2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *dateSpacer;
    QLabel *equity_4;
    QLabel *tradeSimulator_curDate;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *horizontalWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *equity_8;
    QLabel *equity_9;
    QLabel *equity_10;
    QLabel *equity_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *open_price;
    QLabel *high_price;
    QLabel *low_price;
    QLabel *last_price;
    QLabel *simulator_error_box;
    QWidget *verticalWidget1;
    QVBoxLayout *Buttons;
    QPushButton *sendBuySignal;
    QPushButton *sendSellSignal;
    QPushButton *exportOrderFileButton;

    void setupUi(QWidget *TradeSimulator)
    {
        if (TradeSimulator->objectName().isEmpty())
            TradeSimulator->setObjectName(QStringLiteral("TradeSimulator"));
        TradeSimulator->resize(1125, 800);
        verticalLayout = new QVBoxLayout(TradeSimulator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        LeftPanel = new QVBoxLayout();
        LeftPanel->setObjectName(QStringLiteral("LeftPanel"));
        LeftPanel->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(TradeSimulator);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        label_5 = new QLabel(TradeSimulator);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        label = new QLabel(TradeSimulator);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(TradeSimulator);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_4 = new QLabel(TradeSimulator);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        label_3 = new QLabel(TradeSimulator);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);


        LeftPanel->addLayout(horizontalLayout_3);

        tradeSimulator_graphicsGraphDisplay = new QGraphicsView(TradeSimulator);
        tradeSimulator_graphicsGraphDisplay->setObjectName(QStringLiteral("tradeSimulator_graphicsGraphDisplay"));

        LeftPanel->addWidget(tradeSimulator_graphicsGraphDisplay);

        tradeSimulator_returnsAnalysis = new QTableWidget(TradeSimulator);
        tradeSimulator_returnsAnalysis->setObjectName(QStringLiteral("tradeSimulator_returnsAnalysis"));
        tradeSimulator_returnsAnalysis->setSortingEnabled(true);

        LeftPanel->addWidget(tradeSimulator_returnsAnalysis);


        horizontalLayout_2->addLayout(LeftPanel);

        widget = new QWidget(TradeSimulator);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(360, 16777215));
        RightPanel = new QVBoxLayout(widget);
        RightPanel->setObjectName(QStringLiteral("RightPanel"));
        RightPanel->setContentsMargins(-1, -1, -1, 1);
        logoVerticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        RightPanel->addItem(logoVerticalSpacer);

        horizontalWidget = new QWidget(widget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setMaximumSize(QSize(16777215, 80));
        logoLayout = new QHBoxLayout(horizontalWidget);
        logoLayout->setObjectName(QStringLiteral("logoLayout"));
        logoLayout->setSizeConstraint(QLayout::SetFixedSize);
        logo = new QLabel(horizontalWidget);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setMaximumSize(QSize(300, 80));
        logo->setStyleSheet(QStringLiteral(""));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/images/resources/logo.png")));
        logo->setScaledContents(true);
        logo->setAlignment(Qt::AlignCenter);
        logo->setWordWrap(false);
        logo->setMargin(0);

        logoLayout->addWidget(logo);


        RightPanel->addWidget(horizontalWidget);

        companylabel = new QLabel(widget);
        companylabel->setObjectName(QStringLiteral("companylabel"));
        companylabel->setMaximumSize(QSize(16777215, 20));
        companylabel->setOpenExternalLinks(true);

        RightPanel->addWidget(companylabel);

        verticalWidget = new QWidget(widget);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        SummaryLayout = new QVBoxLayout(verticalWidget);
        SummaryLayout->setObjectName(QStringLiteral("SummaryLayout"));
        SummaryLayout->setContentsMargins(-1, -1, -1, 1);
        horizontalWidget1 = new QWidget(verticalWidget);
        horizontalWidget1->setObjectName(QStringLiteral("horizontalWidget1"));
        horizontalWidget1->setMinimumSize(QSize(0, 0));
        horizontalWidget1->setMaximumSize(QSize(16777215, 60));
        equityLine = new QHBoxLayout(horizontalWidget1);
        equityLine->setObjectName(QStringLiteral("equityLine"));
        equity = new QLabel(horizontalWidget1);
        equity->setObjectName(QStringLiteral("equity"));
        equity->setStyleSheet(QLatin1String("font: 14pt \"Verdana\";\n"
"border: 0px;"));

        equityLine->addWidget(equity);

        tradeSimulator_companyName = new QLabel(horizontalWidget1);
        tradeSimulator_companyName->setObjectName(QStringLiteral("tradeSimulator_companyName"));
        tradeSimulator_companyName->setMaximumSize(QSize(267, 16777215));
        tradeSimulator_companyName->setStyleSheet(QLatin1String("font: 14pt \"Verdana\";\n"
"border: 0px;\n"
""));
        tradeSimulator_companyName->setAlignment(Qt::AlignCenter);

        equityLine->addWidget(tradeSimulator_companyName);


        SummaryLayout->addWidget(horizontalWidget1);

        horizontalWidget_2 = new QWidget(verticalWidget);
        horizontalWidget_2->setObjectName(QStringLiteral("horizontalWidget_2"));
        horizontalWidget_2->setMaximumSize(QSize(16777215, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        equity_2 = new QLabel(horizontalWidget_2);
        equity_2->setObjectName(QStringLiteral("equity_2"));
        equity_2->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"border: 0px;"));

        horizontalLayout_4->addWidget(equity_2);

        tradeSimulator_ongoingReturns = new QLabel(horizontalWidget_2);
        tradeSimulator_ongoingReturns->setObjectName(QStringLiteral("tradeSimulator_ongoingReturns"));
        tradeSimulator_ongoingReturns->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"border: 0px;\n"
""));

        horizontalLayout_4->addWidget(tradeSimulator_ongoingReturns, 0, Qt::AlignHCenter);


        SummaryLayout->addWidget(horizontalWidget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        SummaryLayout->addItem(verticalSpacer);

        frame = new QFrame(verticalWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        SummaryLayout->addWidget(frame);

        horizontalWidget2 = new QWidget(verticalWidget);
        horizontalWidget2->setObjectName(QStringLiteral("horizontalWidget2"));
        horizontalLayout = new QHBoxLayout(horizontalWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 1);
        dateSpacer = new QSpacerItem(0, 1, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(dateSpacer);

        equity_4 = new QLabel(horizontalWidget2);
        equity_4->setObjectName(QStringLiteral("equity_4"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        equity_4->setFont(font);
        equity_4->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"border: 0px;"));

        horizontalLayout->addWidget(equity_4);

        tradeSimulator_curDate = new QLabel(horizontalWidget2);
        tradeSimulator_curDate->setObjectName(QStringLiteral("tradeSimulator_curDate"));
        tradeSimulator_curDate->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"border: 0px;\n"
""));

        horizontalLayout->addWidget(tradeSimulator_curDate);


        SummaryLayout->addWidget(horizontalWidget2);

        verticalWidget_2 = new QWidget(verticalWidget);
        verticalWidget_2->setObjectName(QStringLiteral("verticalWidget_2"));
        verticalWidget_2->setMaximumSize(QSize(16777215, 100));
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalWidget_4 = new QWidget(verticalWidget_2);
        horizontalWidget_4->setObjectName(QStringLiteral("horizontalWidget_4"));
        horizontalLayout_6 = new QHBoxLayout(horizontalWidget_4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        equity_8 = new QLabel(horizontalWidget_4);
        equity_8->setObjectName(QStringLiteral("equity_8"));
        equity_8->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"font-weight: bold;\n"
""));

        horizontalLayout_6->addWidget(equity_8, 0, Qt::AlignHCenter);

        equity_9 = new QLabel(horizontalWidget_4);
        equity_9->setObjectName(QStringLiteral("equity_9"));
        equity_9->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"font-weight: bold;\n"
""));

        horizontalLayout_6->addWidget(equity_9, 0, Qt::AlignHCenter);

        equity_10 = new QLabel(horizontalWidget_4);
        equity_10->setObjectName(QStringLiteral("equity_10"));
        equity_10->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"font-weight: bold;\n"
""));

        horizontalLayout_6->addWidget(equity_10, 0, Qt::AlignHCenter);

        equity_11 = new QLabel(horizontalWidget_4);
        equity_11->setObjectName(QStringLiteral("equity_11"));
        equity_11->setStyleSheet(QLatin1String("font: 12pt \"Verdana\";\n"
"font-weight: bold;\n"
""));

        horizontalLayout_6->addWidget(equity_11, 0, Qt::AlignHCenter);


        verticalLayout_3->addWidget(horizontalWidget_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        open_price = new QLabel(verticalWidget_2);
        open_price->setObjectName(QStringLiteral("open_price"));
        open_price->setStyleSheet(QLatin1String("font: 10pt \"Verdana\";\n"
"border: 0px;"));

        horizontalLayout_5->addWidget(open_price, 0, Qt::AlignHCenter);

        high_price = new QLabel(verticalWidget_2);
        high_price->setObjectName(QStringLiteral("high_price"));
        high_price->setStyleSheet(QLatin1String("font: 10pt \"Verdana\";\n"
"border: 0px;"));

        horizontalLayout_5->addWidget(high_price, 0, Qt::AlignHCenter);

        low_price = new QLabel(verticalWidget_2);
        low_price->setObjectName(QStringLiteral("low_price"));
        low_price->setStyleSheet(QLatin1String("font: 10pt \"Verdana\";\n"
"border: 0px;"));

        horizontalLayout_5->addWidget(low_price, 0, Qt::AlignHCenter);

        last_price = new QLabel(verticalWidget_2);
        last_price->setObjectName(QStringLiteral("last_price"));
        last_price->setStyleSheet(QLatin1String("font: 10pt \"Verdana\";\n"
"border: 0px;"));

        horizontalLayout_5->addWidget(last_price, 0, Qt::AlignHCenter);


        verticalLayout_3->addLayout(horizontalLayout_5);


        SummaryLayout->addWidget(verticalWidget_2);

        simulator_error_box = new QLabel(verticalWidget);
        simulator_error_box->setObjectName(QStringLiteral("simulator_error_box"));
        simulator_error_box->setAutoFillBackground(false);
        simulator_error_box->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        SummaryLayout->addWidget(simulator_error_box, 0, Qt::AlignHCenter);

        verticalWidget1 = new QWidget(verticalWidget);
        verticalWidget1->setObjectName(QStringLiteral("verticalWidget1"));
        verticalWidget1->setMinimumSize(QSize(0, 0));
        verticalWidget1->setMaximumSize(QSize(16777215, 200));
        Buttons = new QVBoxLayout(verticalWidget1);
        Buttons->setObjectName(QStringLiteral("Buttons"));
        sendBuySignal = new QPushButton(verticalWidget1);
        sendBuySignal->setObjectName(QStringLiteral("sendBuySignal"));
        sendBuySignal->setStyleSheet(QLatin1String("#TradeSimulator QPushButton {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3498db);\n"
"border: 1px solid #555;\n"
"font-family: Arial;\n"
"color: #ffffff;\n"
"font-size: 16px;\n"
"padding: 10px 5px 10px 5px;\n"
"text-decoration: none;\n"
"}\n"
"\n"
"#TradeSimulator QPushButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3cb1ff);\n"
"}\n"
"\n"
"#TradeSimulator QPushButton:pressed {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3498db);\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/resources/letterB.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendBuySignal->setIcon(icon);
        sendBuySignal->setIconSize(QSize(32, 32));

        Buttons->addWidget(sendBuySignal);

        sendSellSignal = new QPushButton(verticalWidget1);
        sendSellSignal->setObjectName(QStringLiteral("sendSellSignal"));
        sendSellSignal->setStyleSheet(QLatin1String("#TradeSimulator QPushButton {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3498db);\n"
"border: 1px solid #555;\n"
"font-family: Arial;\n"
"color: #ffffff;\n"
"font-size: 16px;\n"
"padding: 10px 5px 10px 5px;\n"
"text-decoration: none;\n"
"}\n"
"\n"
"#TradeSimulator QPushButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3cb1ff);\n"
"}\n"
"\n"
"#TradeSimulator QPushButton:pressed {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3498db);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/resources/letterS.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendSellSignal->setIcon(icon1);
        sendSellSignal->setIconSize(QSize(32, 32));

        Buttons->addWidget(sendSellSignal);

        exportOrderFileButton = new QPushButton(verticalWidget1);
        exportOrderFileButton->setObjectName(QStringLiteral("exportOrderFileButton"));
        exportOrderFileButton->setStyleSheet(QLatin1String("#TradeSimulator QPushButton {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3498db);\n"
"border: 1px solid #555;\n"
"font-family: Arial;\n"
"color: #ffffff;\n"
"font-size: 16px;\n"
"padding: 10px 5px 10px 5px;\n"
"text-decoration: none;\n"
"}\n"
"\n"
"#TradeSimulator QPushButton:hover {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3cb1ff);\n"
"}\n"
"\n"
"#TradeSimulator QPushButton:pressed {\n"
"background: qradialgradient(cx: 0.3, cy: -0.4,\n"
"fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #3498db);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/resources/export_csv.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportOrderFileButton->setIcon(icon2);
        exportOrderFileButton->setIconSize(QSize(32, 32));

        Buttons->addWidget(exportOrderFileButton);


        SummaryLayout->addWidget(verticalWidget1);


        RightPanel->addWidget(verticalWidget);


        horizontalLayout_2->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(TradeSimulator);

        QMetaObject::connectSlotsByName(TradeSimulator);
    } // setupUi

    void retranslateUi(QWidget *TradeSimulator)
    {
        TradeSimulator->setWindowTitle(QApplication::translate("TradeSimulator", "Form", 0));
        label_6->setText(QString());
        label_5->setText(QString());
        label->setText(QApplication::translate("TradeSimulator", "<span style=\"color:blue\">Blue - Buy</span>", 0));
        label_2->setText(QApplication::translate("TradeSimulator", "<html><head/><body><p><span style=\" color:#009940;\">Green - Sell</span></p></body></html>", 0));
        label_4->setText(QString());
        label_3->setText(QString());
        logo->setText(QString());
        companylabel->setText(QApplication::translate("TradeSimulator", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Trade Simulator\342\204\242</span></p></body></html>", 0));
        equity->setText(QApplication::translate("TradeSimulator", "<html><head/><body><p><span style=\" font-weight:600;\">Equity:</span></p></body></html>", 0));
        tradeSimulator_companyName->setText(QApplication::translate("TradeSimulator", "N/A", 0));
        equity_2->setText(QApplication::translate("TradeSimulator", "<html><head/><body><p><span style=\" font-weight:600;\">Overall</span></p><p><span style=\" font-weight:600;\">Returns:</span></p></body></html>", 0));
        tradeSimulator_ongoingReturns->setText(QApplication::translate("TradeSimulator", "0%", 0));
        equity_4->setText(QApplication::translate("TradeSimulator", "<html><head/><body><p><span style=\" font-weight:600;\">Date:</span></p></body></html>", 0));
        tradeSimulator_curDate->setText(QApplication::translate("TradeSimulator", "-", 0));
        equity_8->setText(QApplication::translate("TradeSimulator", "OPEN", 0));
        equity_9->setText(QApplication::translate("TradeSimulator", "HIGH", 0));
        equity_10->setText(QApplication::translate("TradeSimulator", "LOW", 0));
        equity_11->setText(QApplication::translate("TradeSimulator", "LAST", 0));
        open_price->setText(QApplication::translate("TradeSimulator", "0", 0));
        high_price->setText(QApplication::translate("TradeSimulator", "0", 0));
        low_price->setText(QApplication::translate("TradeSimulator", "0", 0));
        last_price->setText(QApplication::translate("TradeSimulator", "0", 0));
        simulator_error_box->setText(QString());
#ifndef QT_NO_TOOLTIP
        sendBuySignal->setToolTip(QApplication::translate("TradeSimulator", "<html><head/><body><p>Send a BUY (B) signal at this moment in time.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendBuySignal->setText(QApplication::translate("TradeSimulator", "Send Buy Signal", 0));
#ifndef QT_NO_TOOLTIP
        sendSellSignal->setToolTip(QApplication::translate("TradeSimulator", "<html><head/><body><p>Send a SELL (S) signal at this moment in time.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendSellSignal->setText(QApplication::translate("TradeSimulator", "Send Sell Signal", 0));
#ifndef QT_NO_TOOLTIP
        exportOrderFileButton->setToolTip(QApplication::translate("TradeSimulator", "<html><head/><body><p>Export recorded simulation data to an order CSV file.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        exportOrderFileButton->setText(QApplication::translate("TradeSimulator", "Export Order File to CSV", 0));
    } // retranslateUi

};

namespace Ui {
    class TradeSimulator: public Ui_TradeSimulator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADESIMULATOR_H
