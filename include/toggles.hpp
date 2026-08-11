#pragma once
#include <string>
#include <vector>
#include <map>

struct Toggle {
    std::string id;
    std::string name;
    std::string category;
    bool enabled;
    std::string description;
};

class ToggleManager {
public:
    static ToggleManager* get();
    
    void addToggle(const std::string& id, const std::string& name, 
                   const std::string& category, const std::string& description = "");
    void setToggleState(const std::string& id, bool state);
    bool getToggleState(const std::string& id) const;
    
    const std::vector<Toggle>& getAllToggles() const;
    std::vector<Toggle> getTogglesByCategory(const std::string& category) const;
    
    void saveToggles();
    void loadToggles();
    
private:
    ToggleManager();
    std::vector<Toggle> m_toggles;
    std::map<std::string, bool> m_toggleStates;
};