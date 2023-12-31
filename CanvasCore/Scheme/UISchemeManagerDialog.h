#ifndef UISCHEMEMANAGERDIALOG_H
#define UISCHEMEMANAGERDIALOG_H

#include "../CustomWidgets/UICustomWidgtes/CustomDialog.h"
#include "../canvascore_global.h"
#include <QWidget>

class UISchemeManagerWidget;
class EASYCANVASCORESHARED_EXPORT UISchemeManagerDialog : public CustomDialog
{
    Q_OBJECT

public:
    explicit UISchemeManagerDialog(QWidget* parent = nullptr);
    ~UISchemeManagerDialog();

private:
    void initUi(void);

    UISchemeManagerWidget* m_pSchemeWidget = nullptr;

private slots:
    void onClickedDeleteButton(void);
    void onClickedOpenButton(void);
};

#endif
