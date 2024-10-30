#include <TDDMUser.h>
#include <ui_TDDMUser.h>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>

TDDMUser::TDDMUser(QWidget *parent)
	: QWidget(parent), ui(new Ui::TDDMUserClass())
{
	ui->setupUi(this);
	connect(ui->btn_set, &QPushButton::pressed, this, &TDDMUser::slotBtnSetPressed);
	connect(ui->btn_reload, &QPushButton::pressed, this, &TDDMUser::slotBtnReloadPressed);
	// m_selectTimer.setFunc(this);
	m_selectTimer.setCallback(std::bind(&TDDMUser::onTimeout, this));
	m_selectTimer.setInterval(40);

}

TDDMUser::~TDDMUser()
{
	delete ui;
}

/// @brief set按钮按下
void TDDMUser::slotBtnSetPressed()
{
	// ui->textEdit->clear();
	// QMessageBox::information(nullptr, "", "1");
	m_selectTimer.start(true);

}

/// @brief reload按钮按下
void TDDMUser::slotBtnReloadPressed()
{
	m_selectTimer.stop();
}

void TDDMUser::onTimeout()
{
	if (1000 < m_index)
	{
		return;
	}

	// qDebug() << "time=" << QDateTime::currentDateTime();
	QDateTime dt = QDateTime::currentDateTime();
	QString strTmp = QString("%1").arg(dt.time().hour(), 2, 10, QLatin1Char('0')) + ":" + \
					QString("%1").arg(dt.time().minute(), 2, 10, QLatin1Char('0')) + ":" + \
					QString("%1").arg(dt.time().second(), 2, 10, QLatin1Char('0')) + "." + \
					QString("%1").arg(dt.time().msec(), 3, 10, QLatin1Char('0')); 
	qDebug() << strTmp;
	// ui->textEdit->append(strTmp);

	++ m_index;
}