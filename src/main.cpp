#include <geode/Geode.hpp>
#include "../include/managers.hpp"
#include "../include/floating_button.hpp"
#include "../include/menu.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
    // Initialize managers on mod load
    ToggleManager::get().init();
    ThemeManager::get().initMobileThemes();
    ThemeManager::get().initPCThemes();
    
    log::info("Gravity Mod Loaded!");
    log::info("Total Toggles: {}", ToggleManager::get().getTotalCount());
    log::info("Mobile Themes: 45");
    log::info("PC Themes: 10");
}
