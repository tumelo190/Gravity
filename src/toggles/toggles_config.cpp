#include "../../include/toggles.hpp"

void initializeToggles(ToggleManager* manager) {
    // GAMEPLAY TOGGLES
    manager->addToggle("god_mode", "God Mode", "Gameplay", "Prevents taking damage and dying");
    manager->addToggle("instant_complete", "Instant Complete", "Gameplay", "Complete levels instantly");
    manager->addToggle("no_clip", "No Clip", "Gameplay", "Pass through all obstacles");
    manager->addToggle("speed_hack", "Speed Hack", "Gameplay", "Modify game speed (1x, 2x, 0.5x)");
    manager->addToggle("jump_hack", "Jump Hack", "Gameplay", "Unlimited jump height");
    manager->addToggle("fly_mode", "Fly Mode", "Gameplay", "Fly around freely");
    manager->addToggle("gravity_off", "Gravity Off", "Gameplay", "Disable gravity effects");
    
    // UI TOGGLES
    manager->addToggle("hide_ui", "Hide UI", "Visual", "Hide all UI elements");
    manager->addToggle("hide_hud", "Hide HUD", "Visual", "Hide heads-up display");
    manager->addToggle("practice_button_gone", "Practice Button Gone", "Visual", "Remove practice button");
    manager->addToggle("hide_pause_menu", "Hide Pause Menu", "Visual", "Hide pause menu button");
    manager->addToggle("hide_score", "Hide Score", "Visual", "Hide score counter");
    manager->addToggle("hide_percentage", "Hide Percentage", "Visual", "Hide level percentage");
    manager->addToggle("hide_fps", "Hide FPS", "Visual", "Hide FPS counter");
    
    // VISIBILITY TOGGLES
    manager->addToggle("hide_spikes", "Hide Spikes", "Visual", "Make spikes invisible");
    manager->addToggle("hide_platforms", "Hide Platforms", "Visual", "Make platforms invisible");
    manager->addToggle("hide_enemies", "Hide Enemies", "Visual", "Make enemies invisible");
    manager->addToggle("hide_background", "Hide Background", "Visual", "Hide level background");
    manager->addToggle("hide_particles", "Hide Particles", "Visual", "Disable particle effects");
    
    // LEVEL MODIFICATONS
    manager->addToggle("noclip_mode", "No Clip Mode", "Level Mods", "Walk through walls");
    manager->addToggle("large_player", "Large Player", "Level Mods", "Make player size bigger");
    manager->addToggle("small_player", "Small Player", "Level Mods", "Make player size smaller");
    manager->addToggle("rainbow_player", "Rainbow Player", "Level Mods", "Color player rainbow");
    manager->addToggle("invisible_player", "Invisible Player", "Level Mods", "Make player invisible");
    
    // MUSIC & SOUND
    manager->addToggle("mute_music", "Mute Music", "Audio", "Disable background music");
    manager->addToggle("mute_sfx", "Mute SFX", "Audio", "Disable sound effects");
    manager->addToggle("mute_all", "Mute All", "Audio", "Disable all audio");
    
    // CAMERA & VIEW
    manager->addToggle("zoom_in", "Zoom In", "Camera", "Zoom camera in");
    manager->addToggle("zoom_out", "Zoom Out", "Camera", "Zoom camera out");
    manager->addToggle("free_camera", "Free Camera", "Camera", "Move camera freely");
    manager->addToggle("top_down_view", "Top Down View", "Camera", "View from above");
    
    // PHYSICS TOGGLES
    manager->addToggle("disable_gravity", "Disable Gravity", "Physics", "Remove gravity");
    manager->addToggle("low_gravity", "Low Gravity", "Physics", "Reduce gravity effect");
    manager->addToggle("high_gravity", "High Gravity", "Physics", "Increase gravity effect");
    manager->addToggle("no_friction", "No Friction", "Physics", "Remove friction effects");
    
    // COLLISION TOGGLES
    manager->addToggle("no_collision", "No Collision", "Physics", "Disable collision detection");
    manager->addToggle("collision_debug", "Collision Debug", "Physics", "Show collision boxes");
    
    // GAMEPLAY ASSISTS
    manager->addToggle("auto_jump", "Auto Jump", "Assist", "Automatically jump");
    manager->addToggle("auto_tap", "Auto Tap", "Assist", "Automatically tap");
    manager->addToggle("slow_motion", "Slow Motion", "Assist", "Slow down game time");
    manager->addToggle("frame_advance", "Frame Advance", "Assist", "Advance one frame");
    
    // COSMETICS
    manager->addToggle("rainbow_mode", "Rainbow Mode", "Cosmetics", "Enable rainbow effects");
    manager->addToggle("neon_mode", "Neon Mode", "Cosmetics", "Neon glow effects");
    manager->addToggle("dark_mode", "Dark Mode", "Cosmetics", "Dark theme for UI");
    manager->addToggle("custom_colors", "Custom Colors", "Cosmetics", "Customize colors");
}
