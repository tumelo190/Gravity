#include "../../include/toggles.hpp"
#include <vector>
#include <string>

// MAIN MENU - 200+ TOGGLES
void initializeMainMenuToggles(ToggleManager* manager) {
    
    // GAMEPLAY TOGGLES (50)
    manager->addToggle("god_mode", "God Mode", "Gameplay", "Never take damage");
    manager->addToggle("instant_complete", "Instant Complete", "Gameplay", "Beat level instantly");
    manager->addToggle("no_clip", "No Clip", "Gameplay", "Pass through walls");
    manager->addToggle("speed_1x", "Speed 1x", "Gameplay", "Normal speed");
    manager->addToggle("speed_2x", "Speed 2x", "Gameplay", "Double speed");
    manager->addToggle("speed_05x", "Speed 0.5x", "Gameplay", "Half speed");
    manager->addToggle("jump_hack", "Jump Hack", "Gameplay", "Unlimited jump");
    manager->addToggle("fly_mode", "Fly Mode", "Gameplay", "Fly around");
    manager->addToggle("gravity_off", "Gravity Off", "Gameplay", "No gravity");
    manager->addToggle("low_gravity", "Low Gravity", "Gameplay", "Less gravity");
    manager->addToggle("high_gravity", "High Gravity", "Gameplay", "More gravity");
    manager->addToggle("no_collision", "No Collision", "Gameplay", "Ignore collisions");
    manager->addToggle("auto_jump", "Auto Jump", "Gameplay", "Auto jump");
    manager->addToggle("auto_tap", "Auto Tap", "Gameplay", "Auto tap");
    manager->addToggle("slow_motion", "Slow Motion", "Gameplay", "Slow time");
    manager->addToggle("frame_advance", "Frame Advance", "Gameplay", "One frame at time");
    manager->addToggle("freeze_game", "Freeze Game", "Gameplay", "Pause game");
    manager->addToggle("practice_mode", "Practice Mode", "Gameplay", "Infinite tries");
    manager->addToggle("no_spike_damage", "No Spike Damage", "Gameplay", "Spikes safe");
    manager->addToggle("no_saw_damage", "No Saw Damage", "Gameplay", "Saws safe");
    manager->addToggle("invincible_orbs", "Invincible Orbs", "Gameplay", "Orbs protect");
    manager->addToggle("unlimited_orbs", "Unlimited Orbs", "Gameplay", "Infinite orbs");
    manager->addToggle("bypass_gates", "Bypass Gates", "Gameplay", "Pass gates");
    manager->addToggle("unlock_levels", "Unlock All Levels", "Gameplay", "All levels open");
    manager->addToggle("unlock_chests", "Unlock Chests", "Gameplay", "Open all chests");
    manager->addToggle("no_death_animation", "No Death Animation", "Gameplay", "Skip death animation");
    manager->addToggle("instant_respawn", "Instant Respawn", "Gameplay", "Respawn fast");
    manager->addToggle("checkpoint_anywhere", "Checkpoint Anywhere", "Gameplay", "Place checkpoints");
    manager->addToggle("no_wave_segment", "Skip Wave", "Gameplay", "Skip wave mode");
    manager->addToggle("no_ball_segment", "Skip Ball", "Gameplay", "Skip ball mode");
    manager->addToggle("no_ship_segment", "Skip Ship", "Gameplay", "Skip ship mode");
    manager->addToggle("no_ufo_segment", "Skip UFO", "Gameplay", "Skip UFO mode");
    manager->addToggle("no_spider_segment", "Skip Spider", "Gameplay", "Skip spider mode");
    manager->addToggle("no_swing_segment", "Skip Swing", "Gameplay", "Skip swing mode");
    manager->addToggle("rainbow_cube", "Rainbow Cube", "Gameplay", "Rainbow colors");
    manager->addToggle("cube_always", "Cube Always", "Gameplay", "Stay cube");
    manager->addToggle("perfect_timing", "Perfect Timing", "Gameplay", "Perfect inputs");
    manager->addToggle("instant_portal", "Instant Portal", "Gameplay", "Teleport instantly");
    manager->addToggle("no_portal_effect", "No Portal Effect", "Gameplay", "Skip portal animation");
    manager->addToggle("mega_gravity", "Mega Gravity", "Gameplay", "Extreme gravity");
    manager->addToggle("anti_gravity", "Anti Gravity", "Gameplay", "Reverse gravity");
    manager->addToggle("phase_through", "Phase Through", "Gameplay", "Ghost mode");
    manager->addToggle("one_hit_wonder", "One Hit Mode", "Gameplay", "One hit to win");
    manager->addToggle("double_jump", "Double Jump", "Gameplay", "Jump twice");
    manager->addToggle("triple_jump", "Triple Jump", "Gameplay", "Jump three times");
    manager->addToggle("wall_jump", "Wall Jump", "Gameplay", "Jump off walls");
    manager->addToggle("dash_ability", "Dash Ability", "Gameplay", "Dash forward");
    manager->addToggle("time_manipulation", "Time Manipulation", "Gameplay", "Control time");
    
    // VISUAL TOGGLES (50)
    manager->addToggle("hide_ui", "Hide UI", "Visual", "Hide all UI");
    manager->addToggle("hide_hud", "Hide HUD", "Visual", "Hide HUD");
    manager->addToggle("hide_pause_button", "Hide Pause Button", "Visual", "Hide pause");
    manager->addToggle("practice_button_gone", "Practice Button Gone", "Visual", "No practice");
    manager->addToggle("hide_score", "Hide Score", "Visual", "No score shown");
    manager->addToggle("hide_percentage", "Hide Percentage", "Visual", "No percent shown");
    manager->addToggle("hide_fps", "Hide FPS", "Visual", "Hide FPS counter");
    manager->addToggle("hide_spikes", "Hide Spikes", "Visual", "Invisible spikes");
    manager->addToggle("hide_platforms", "Hide Platforms", "Visual", "Invisible platforms");
    manager->addToggle("hide_enemies", "Hide Enemies", "Visual", "Invisible enemies");
    manager->addToggle("hide_background", "Hide Background", "Visual", "No background");
    manager->addToggle("hide_particles", "Hide Particles", "Visual", "No particles");
    manager->addToggle("hide_objects", "Hide Objects", "Visual", "No objects");
    manager->addToggle("hide_ground", "Hide Ground", "Visual", "Invisible ground");
    manager->addToggle("hide_player", "Hide Player", "Visual", "Invisible player");
    manager->addToggle("transparent_player", "Transparent Player", "Visual", "See-through");
    manager->addToggle("glow_player", "Glow Player", "Visual", "Glowing player");
    manager->addToggle("rainbow_player", "Rainbow Player", "Visual", "Rainbow player");
    manager->addToggle("neon_player", "Neon Player", "Visual", "Neon glow");
    manager->addToggle("giant_player", "Giant Player", "Visual", "Big player");
    manager->addToggle("tiny_player", "Tiny Player", "Visual", "Small player");
    manager->addToggle("hide_trail", "Hide Trail", "Visual", "No trail");
    manager->addToggle("rainbow_trail", "Rainbow Trail", "Visual", "Rainbow trail");
    manager->addToggle("thick_trail", "Thick Trail", "Visual", "Thick trail");
    manager->addToggle("hide_effects", "Hide Effects", "Visual", "No effects");
    manager->addToggle("hide_shadows", "Hide Shadows", "Visual", "No shadows");
    manager->addToggle("show_hitbox", "Show Hitbox", "Visual", "See hitbox");
    manager->addToggle("dark_mode", "Dark Mode", "Visual", "Dark theme");
    manager->addToggle("light_mode", "Light Mode", "Visual", "Light theme");
    manager->addToggle("hide_menu_background", "Hide Menu Background", "Visual", "Clear menu");
    manager->addToggle("blur_background", "Blur Background", "Visual", "Blurry");
    manager->addToggle("grayscale_mode", "Grayscale Mode", "Visual", "Black and white");
    manager->addToggle("high_contrast", "High Contrast", "Visual", "More contrast");
    manager->addToggle("color_blind_mode", "Color Blind Mode", "Visual", "Color filter");
    manager->addToggle("small_font", "Small Font", "Visual", "Tiny text");
    manager->addToggle("large_font", "Large Font", "Visual", "Big text");
    manager->addToggle("hide_notifications", "Hide Notifications", "Visual", "No pop-ups");
    manager->addToggle("hide_dialogs", "Hide Dialogs", "Visual", "No dialogs");
    manager->addToggle("simplified_ui", "Simplified UI", "Visual", "Minimal UI");
    manager->addToggle("full_screen_gameplay", "Full Screen", "Visual", "Full screen");
    manager->addToggle("inverted_colors", "Inverted Colors", "Visual", "Inverted");
    manager->addToggle("sepia_mode", "Sepia Mode", "Visual", "Sepia tone");
    manager->addToggle("neon_mode", "Neon Mode", "Visual", "Neon colors");
    manager->addToggle("retro_mode", "Retro Mode", "Visual", "8-bit style");
    manager->addToggle("blur_ui", "Blur UI", "Visual", "Blurry UI");
    manager->addToggle("pixelated_mode", "Pixelated Mode", "Visual", "Pixelated");
    manager->addToggle("cinematic_mode", "Cinematic Mode", "Visual", "Movie mode");
    manager->addToggle("color_cycle", "Color Cycle", "Visual", "Cycling colors");
}

// PROFILE SYSTEM HEADER
struct ProfileToggle {
    std::string id;
    std::string name;
    bool enabled;
};

struct UserProfile {
    std::string name;
    std::vector<ProfileToggle> tab1_toggles;
    std::vector<ProfileToggle> tab2_toggles;
    std::vector<ProfileToggle> tab3_toggles;
    std::vector<ProfileToggle> tab4_toggles;
    std::vector<ProfileToggle> tab5_toggles;
};

struct GravityDevProfile {
    std::string name;
    // Optimization Tab - Makes menu smoother
    std::vector<ProfileToggle> optimization_toggles;
    // Customization Tab - Different menu styles
    std::vector<ProfileToggle> customization_toggles;
};

class ProfileManager {
public:
    void createProfile(const std::string& name);
    void createGravityDevProfile(const std::string& name);
    void createCustomToggle(const std::string& id, const std::string& name);
    void setMenuStyle(const std::string& style);
};
