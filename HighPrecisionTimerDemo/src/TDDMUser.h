/// ----------------------------------------------------
/// @file TDDMUser.h
/// @author oct (oct@tengden.com)
/// @brief 用户配置程序用户界面
/// @version 0.1
/// @date 2024-08-11
/// 
/// @copyright Copyright (c) 2024
/// 
/// ----------------------------------------------------
#pragma once

#include <QWidget>
#include <HighPrecisionTimer.h>

class QComboBox;

namespace Ui { class TDDMUserClass; };

/// @brief 用户配置接口主程序
class TDDMUser : public QWidget
{
	Q_OBJECT
public:
	TDDMUser(QWidget *parent = nullptr);
	~TDDMUser();

	void onTimeout();

private slots:
	/// @brief set按钮按下
	void slotBtnSetPressed();
	
	/// @brief reload按钮按下
	void slotBtnReloadPressed();

private:
	Ui::TDDMUserClass *ui{nullptr};
	HighPrecisionTimer		m_selectTimer;

	int 	m_index{0};
};

