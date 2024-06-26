#ifndef MAINFRAME_H
#define MAINFRAME_H

#include "IMsgBox.h"
#include <wx/wx.h>
/**
 * @file MainFrame.h
 * @brief Данный заголовочный файл содержит описание класса главного окна
 * приложения.
 */

/**
 * @brief Класс, отвечающий за главное окно GUI приложения данного проекта.
 */
class MainFrame : public wxFrame {
  public:
    /**
     * @brief Конструктор, отвечающий за создание экземпляра класса главного
     * окна.
     * @param title название, которое будет отображаться в верхней панели GUI
     * приложения.
     * @param msg_box указатель на экземпляр класса IMsgBox, необходимый для
     * вывода окна-сообщений.
     */
    MainFrame(const wxString &title, IMsgBox *msg_box);
    /**
     * @brief Конструктор, необходимый для проведения mock тестов.
     * @param msg_box указатель на экземпляр класса IMsgBox, необходимый для
     * вывода окна-сообщений.
     */
    MainFrame(IMsgBox *msg_box);
    /**
     * @brief метод, вызываемый при нажатии на кнопку в правом верхнем углу со
     * знаком "?". Выводит окно сообщения со справкой.
     * param evt ссылка на
     * событие, которое произошло с кнопкой helpButton.
     */
    void OnHelpButtonClicked(wxCommandEvent &evt);
    /**
     * @brief метод, вызываемый при нажатии на кнопку "Далее" в GUI приложения.
     * Выводит окно сообщения с предупреждениями, в случае некорректно введённых
     * данных, и окно с надписью об успешном расшифровании или зашифровании в
     * противном случае.
     * @param evt ссылка на событие, которое произошло с кнопкой button.
     */
    void OnButtonClicked(wxCommandEvent &evt);
    /**
     * @brief метод, вызываемый при нажатии на кнопку в правом верхнем углу со
     * знаком "i". Запускает браузер по умолчанию на странице с url:
     * https://internet-law.ru/gosts/gost/70509/.
     * @param evt сылка на событие, которое произошло с кнопкой sourceButton.
     */
    void OnSourceButtonClicked(wxCommandEvent &evt);

  private:
    /**
     * @brief Указатель на первую форму, в которую необходимо ввести абсолютный
     * путь к зашифровываемому или расшифровываемому файлу.
     */
    wxTextCtrl *m_textCtrl_1;
    /**
     * @brief Указатель на вторую форму, в которую необходимо ввести абсолютный
     * путь к файлу с ключом.
     */
    wxTextCtrl *m_textCtrl_2;
    /**
     * @brief Указатель на третью форму, в которую необходимо ввести абсолютный
     * путь для сохранения зашифровываемого или расшифровываемого файла.
     */
    wxTextCtrl *m_textCtrl_3;
    /**
     * @brief Указатель на поле выбора мода(1 - Зашифрование, 2 -
     * Расшифрование).
     */
    wxChoice *choice;
    /**
     * @brief Указатель на экземпляр класса IMsgBox, содержащего метод Show,
     * необходимый для создания окна-сообщения.
     */
    IMsgBox *m_msg_box;
};

#endif
