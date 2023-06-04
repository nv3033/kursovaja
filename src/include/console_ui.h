
#include<vector>
#include<imgui.h>
#include<imgui_impl_glfw.h>
#include<imgui_impl_opengl3.h>
#include<iostream>
#include<imgui_demo.cpp>
#include"objectss.h"
#include<map>
#include <string>




 

class console
{
public:
    console() = default;
    console(const console& rhs);
    ~console();

    std::vector<Wall> walls;
    int WallsCount = 0;

    static int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
    {
        ExampleAppConsole* console = (ExampleAppConsole*)data->UserData;
        return console->TextEditCallback(data);
    }

    char log_[100000] = "";
    bool clicked = 0;
    int curind;
    bool is_in_walls;
    //Camera camera;

    static int   Stricmp(const char* s1, const char* s2) { int d; while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; } return d; }
    static int   Strnicmp(const char* s1, const char* s2, int n) { int d = 0; while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; n--; } return d; }
    static char* Strdup(const char* s) { IM_ASSERT(s); size_t len = strlen(s) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)s, len); }
    static void  Strtrim(char* s) { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }

    void console::Draw(const char* title, bool* p_open)
    {

        ImGui::SetNextWindowSize(ImVec2(0, 0), ImGuiCond_FirstUseEver);
        ImGui::Begin("console", (bool *)1, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
        if (ImGui::BeginPopupContextItem())
        {
            if (ImGui::MenuItem("Close Console"))
                *p_open = false;
            ImGui::EndPopup();
        }
        bool reclaim_focus = false;
        ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_EscapeClearsAll | 
            ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
        if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf)), input_text_flags, &TextEditCallbackStub, (void*)this)
        {
            StringCommand = InputBuf;
            Strtrim(StringCommand);
            if (StringCommand[0] && ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Enter))) {
                SetCommand(StringCommand);
            }
            strcpy(StringCommand, "");
            reclaim_focus = true;
        }
        ExeCommand();
        if (ImGui::Button("Clear"))
            clicked=true;
        if (clicked)
        {
            memset(log_, 0, sizeof(log_));
            clicked = false;
        }

        ImGui::Separator();
        ImGui::SetScrollHereY;
        ImGui::Text(log_);
        ImGui::SetItemDefaultFocus();
        if (reclaim_focus)
            ImGui::SetKeyboardFocusHere(-1); ImGui::End();

}
    void console::ExeCommand() {
        //camera.Update(halls, HallsCount);
    }
    void console::SetCommand(char* Command) {
        std::string StringCommand(Command);
        std::cout << "Command Input:: '" << StringCommand << "' " << std::endl;
        addlogstr_(StringCommand);

        int numspaces = 0;
        for (int i = 0; i < StringCommand.size(); i++)
            if (StringCommand[i] == ' ') { numspaces++; }

        if (numspaces == 1 && StringCommand.length() < 100 && StringCommand.length() > 4) {
            std::map<std::string, int> MapCommand;
            MapCommand[""] = 0;
            MapCommand["adwl"] = 1;
            MapCommand["wall"] = 2;
            MapCommand["stwl"] = 3;
            MapCommand["delt"] = 4;
            MapCommand["save"] = 5;
            MapCommand["wp1x"] = 6;
            MapCommand["wp1y"] = 7;
            MapCommand["wp2x"] = 8;
            MapCommand["wp2y"] = 9;

            switch (MapCommand[StringCommand.substr(0, 4)])
            {
            case 1:
                add_wall(StringCommand.substr(5, StringCommand.length()));
                addlog_("\n");
                addlog_("::wall added");
                break;
            case 2:
                    if (walls.size() > 0) {
                        if (StringCommand.substr(5, StringCommand.length()) == "list") {
                            addlog_(":: walls -> ");
                            for (int i = 0; i < walls.size(); i++)
                            {
                                addlogstr_(std::to_string(walls[i].id.id) + " " + walls[i].name);
                            }
                            addlog_("\n");
                        }
                        else if (StringCommand.substr(5, StringCommand.length()) == "delete") {
                                walls.erase(walls.begin() + curind);
                                addlog_("\n");
                                addlog_("::wall deleted");
                                WallsCount--;
                        }
                        else {

                            addlog_("::ERROR -> invalid data");
                        }
                    }
                    else {
                        addlog_("::ERROR -> no wallls");
                    }
                break;
            case 3:
                is_in_walls = false;
                for (int i = 0; i < WallsCount; i++) {
                    //std::cout << std::to_string(walls[i].id.id) << " " << StringCommand.substr(5, StringCommand.length()) << std::endl;
                    if (std::to_string(walls[i].id.id) == StringCommand.substr(5, StringCommand.length())) {
                        curind = i;
                        is_in_walls = true;
                        break;
                    }
                }
                if (!is_in_walls) {
                    addlog_("::ERROR -> not in the list");
                }
                else {
                    std::string s = "::wall " + walls[curind].name + " is now being edited!";
                    addlogstr_(s);
                }
                break;
            case 4:
                break;
            case 6:
                StringCommand.erase(0, StringCommand.find(" ") + 1);
                walls[curind].pos1[0] = std::stoi(StringCommand);
                addlog_("::your wall position No.1 X is now set");
                break;
            case 7:
                StringCommand.erase(0, StringCommand.find(" ") + 1);
                walls[curind].pos1[1] = std::stoi(StringCommand);
                addlog_("::your wall position No.1 Y is now set");
                break;
            case 8:
                StringCommand.erase(0, StringCommand.find(" ") + 1);
                walls[curind].pos2[0] = std::stoi(StringCommand);
                addlog_("::your wall position No.2 X is now set");
                break;
            case 9:
                StringCommand.erase(0, StringCommand.find(" ") + 1);
                walls[curind].pos2[1] = std::stoi(StringCommand);
                addlog_("::your wall position No.2 Y is now set");
                break;
            default:
                addlog_("::ERROR -> invalid data");
                break;
            }
        }
        else {
            addlog_("::ERROR -> invalid command form");
        }
    }
    
    void addlog_(char* s) {
        std::strcat(log_, s);
        std::strcat(log_, "\n");
    } 
    void addlogstr_(std::string s) {
        char const* cpchar = s.c_str();
        char pchar[100];
        for (int i = 0; i < 100; i++)
            pchar[i] = ' ';
        for (int i = 0; i < s.length(); i++)
            pchar[i] = cpchar[i];
        addlog_(pchar);
    }

    void add_wall(std::string name) {
        int new_id = 0;
        bool not_in_mass = false;
        while (!not_in_mass) {
            not_in_mass = true;
            for (int i = 0; i < WallsCount; i++)
                if (walls[i].id.id == new_id)
                {
                    not_in_mass = false; new_id += 1; break;
                }
        }
        Wall nw;
        nw.id.id = new_id;
        nw.draw = false;
        nw.name = name;
        nw.pos1[0] = 1;
        nw.pos1[1] = 1;
        nw.pos2[0] = 2;
        nw.pos2[1] = 1;
        walls.push_back(nw);
        std::string s = std::to_string(new_id);
        char const* cpchar = s.c_str();
        char pchar[4];
        for (int i = 0; i < 4; i++)
            pchar[i] = cpchar[i];
        addlog_("::id -> ");
        addlog_(pchar);
        WallsCount += 1;
    }

    private:
        char                  InputBuf[256];
        char* StringCommand;
        std::vector<char*>       Items;
        std::vector<const char*> Commands;
        std::vector<char*>       History;
        int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
        //ImGuiTextFilter       Filter;
        bool                  AutoScroll;
        bool                  ScrollToBottom;
        
};

console::~console() {}
/*class commands
{
public:
    commands() = default;
    commands(const console& rhs);
    ~commands();

    */
//
//private:
//
//};
//
//commands::~commands() {

//}