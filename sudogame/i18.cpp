#include "i18n.hpp"

#include <cassert>

I18n::Dict english = {
    {I18n::Key::ASK_KEY_MAP, "Keymap mode: 1 WASD 2 VIM"},
    {I18n::Key::INPUT_ERROR, "Input error!"},
    {I18n::Key::LOAD_PROGRESS_FAIL, "Load progress failed!"},
    {I18n::Key::ASK_QUIT, "Quit game? [Y/N]"},
    {I18n::Key::ASK_SAVE, "Do you want to save the game progress? [Y/N]"},
    {I18n::Key::ASK_SAVE_PATH, "Input path of the progress file:"},
    {I18n::Key::FILE_EXIST_ERROR, "This file is already exist."},
    {I18n::Key::CONTINUE, "Continue."},
    {I18n::Key::UNDO_ERROR, "No more action to undo."},
    {I18n::Key::CONGRATULATION, "Congratulation! You Win!"},
    {I18n::Key::NOT_COMPLETED, "Sorry, not completed."},
    {I18n::Key::ASK_DIFFICULTY, "Select difficulty: 1 Easy 2 Normal 3 Hard"},
};
I18n::Dict chinese = {
    {I18n::Key::ASK_KEY_MAP, "���ð���ģʽ: 1 WASD 2 VIM"},
    {I18n::Key::INPUT_ERROR, "�������!"},
    {I18n::Key::LOAD_PROGRESS_FAIL, "���ش浵ʧ��!"},
    {I18n::Key::ASK_QUIT, "�˳���Ϸ? [Y/N]"},
    {I18n::Key::ASK_SAVE, "�������? [Y/N]"},
    {I18n::Key::ASK_SAVE_PATH, "����浵�ļ�·��:"},
    {I18n::Key::FILE_EXIST_ERROR, "�ļ��Ѵ���"},
    {I18n::Key::CONTINUE, "����"},
    {I18n::Key::UNDO_ERROR, "û�п��Գ����Ķ���"},
    {I18n::Key::CONGRATULATION, "��ϲ! ��⿪������!"},
    {I18n::Key::NOT_COMPLETED, "�Բ���, ��δ���"},
    {I18n::Key::ASK_DIFFICULTY, "�����Ѷ�: 1�� 2��ͨ 3����"},
};

I18n::I18n() : dict_(&english) {}

I18n& I18n::Instance() 
{
    static I18n i18n;
    return i18n;
}

void I18n::SetLanguage(Language language)
{
    switch (language)
    {
    case Language::ENGLISH:
        dict_ = &english;
        break;
    case Language::CHINESE:
        dict_ = &english;
        break;
    case Language::MAX:
    default:
        assert(false);
    }
}

std::string I18n::Get(Key key) const
{
    assert(dict_->count(key));
    return (*dict_)[key];
}