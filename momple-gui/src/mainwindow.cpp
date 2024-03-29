/*
 * mainwindow.cpp is a part of the Momple frontend to Tessa.
 * Copyright (C) 2007	Sander Dijkhuis
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "mainwindow.h"

#include "accountwidget.h"
#include "contact.h"
#include "contactwidget.h"
#include "signinwidget.h"

#include <QApplication>
#include <QFrame>
#include <QIcon>
#include <QScrollArea>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
	setWindowIcon(QIcon(":/icons/momple-16x16.png"));
	setWindowTitle("Momple");

	resize(240, 360);

	_mainLayout = new QVBoxLayout;
	_mainLayout->setMargin(0);
	_mainLayout->setSpacing(0);
	setLayout(_mainLayout);

	AccountWidget *accountWidget = new AccountWidget;
	QFrame *accountFrame = new QFrame;
	accountFrame->setObjectName("accountFrame");
	accountFrame->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
	_accountFrameLayout = new QVBoxLayout;
	_accountFrameLayout->setMargin(0);
	_accountFrameLayout->setSpacing(0);
	accountFrame->setLayout(_accountFrameLayout);
	accountFrame->layout()->addWidget(accountWidget); 
	_mainLayout->addWidget(accountFrame, 0, Qt::AlignTop);

	//connect(cm, SIGNAL(signedIn()), SLOT(cm_signedIn()));

	// Temporary: immediately show the roster window
	cm_signedIn();
}

void MainWindow::closeEvent(QCloseEvent *)
{
}

void MainWindow::cm_signedIn()
{
	_contactList = new QWidget;
        _contactList->setObjectName("contactList");
	QVBoxLayout *contactListLayout = new QVBoxLayout;
	contactListLayout->setMargin(0);
	contactListLayout->setSpacing(0);
	_contactList->setLayout(contactListLayout);
	QScrollArea *contactArea = new QScrollArea;
	contactArea->setBackgroundRole(QPalette::Base);
	//contactArea->setAutoFillBackground(true);
	contactArea->setObjectName("contactArea");
	contactArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	contactArea->setWidgetResizable(true);
	//contactArea->setLineWidth(0);
	//contactArea->setStyleSheet("QScrollArea { border-top: 1px solid; }");

#if 0
	Contact *contact;
	ContactWidget *contactWidget;
	foreach (contact, cm->getContacts())
	{
		contactWidget = new ContactWidget(0, contact);
		_contactListLayout->addWidget(contactWidget, 0, Qt::AlignTop);
	}
#endif

	Contact *testContact = new Contact(0, "test@example", "Uncle Scrooge");
	ContactWidget *testContactWidget = new ContactWidget(0, testContact);
	contactListLayout->addWidget(testContactWidget, 0, Qt::AlignTop);
	testContact = new Contact(0, "kjhkj", "Gyro Gearloose");
	testContactWidget = new ContactWidget(0, testContact);
	contactListLayout->addWidget(testContactWidget, 0, Qt::AlignTop);
	testContact = new Contact(0, "kjhkj", "Daisy Duck");
	testContactWidget = new ContactWidget(0, testContact);
	contactListLayout->addWidget(testContactWidget, 0, Qt::AlignTop);
	testContact = new Contact(0, "kjhkj", "Huey Duck");
	testContactWidget = new ContactWidget(0, testContact);
	contactListLayout->addWidget(testContactWidget, 0, Qt::AlignTop);
	testContact = new Contact(0, "kjhkj", "Louie Duck");
	testContactWidget = new ContactWidget(0, testContact);
	contactListLayout->addWidget(testContactWidget, 0, Qt::AlignTop);
	testContact = new Contact(0, "kjhkj", "Dewey Duck");
	testContactWidget = new ContactWidget(0, testContact);
	contactListLayout->addWidget(testContactWidget, 0, Qt::AlignTop);
	contactListLayout->addStretch();

	contactArea->setWidget(_contactList);
	_mainLayout->addWidget(contactArea, 1);

	_footerWidget = new FooterWidget();
	_mainLayout->addWidget(_footerWidget, 0);
}
