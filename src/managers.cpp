#include "../include/managers.hpp"
#include <fstream>
#include <sstream>

ToggleManager& ToggleManager::get() {
    static ToggleManager instance;
    return instance;
}

void ToggleManager::init() {
    // GAMEPLAY TOGGLES (35 toggles)
    m_toggles.push_back({"god_mode", "God Mode", ToggleCategory::Gameplay, false, "Never take damage"});
    m_toggles.push_back({"instant_complete", "Instant Complete", ToggleCategory::Gameplay, false, "Beat level instantly"});
    m_toggles.push_back({"no_clip", "No Clip", ToggleCategory::Gameplay, false, "Pass through walls"});
    m_toggles.push_back({"jump_hack", "Jump Hack", ToggleCategory::Gameplay, false, "Unlimited jump"});
    m_toggles.push_back({"fly_mode", "Fly Mode", ToggleCategory::Gameplay, false, "Fly around"});
    m_toggles.push_back({"no_collision", "No Collision", ToggleCategory::Gameplay, false, "Ignore collisions"});
    m_toggles.push_back({"auto_jump", "Auto Jump", ToggleCategory::Gameplay, false, "Auto jump"});
    m_toggles.push_back({"auto_tap", "Auto Tap", ToggleCategory::Gameplay, false, "Auto tap"});
    m_toggles.push_back({"slow_motion", "Slow Motion", ToggleCategory::Gameplay, false, "Slow time"});
    m_toggles.push_back({"frame_advance", "Frame Advance", ToggleCategory::Gameplay, false, "One frame at time"});
    m_toggles.push_back({"freeze_game", "Freeze Game", ToggleCategory::Gameplay, false, "Pause game"});
    m_toggles.push_back({"practice_mode", "Practice Mode", ToggleCategory::Practice, false, "Infinite tries"});
    m_toggles.push_back({"no_spike_damage", "No Spike Damage", ToggleCategory::Gameplay, false, "Spikes safe"});
    m_toggles.push_back({"no_saw_damage", "No Saw Damage", ToggleCategory::Gameplay, false, "Saws safe"});
    m_toggles.push_back({"invincible_orbs", "Invincible Orbs", ToggleCategory::Gameplay, false, "Orbs protect"});
    m_toggles.push_back({"bypass_gates", "Bypass Gates", ToggleCategory::Utility, false, "Pass gates"});
    m_toggles.push_back({"unlock_levels", "Unlock All Levels", ToggleCategory::Utility, false, "All levels open"});
    m_toggles.push_back({"no_death_animation", "No Death Animation", ToggleCategory::Gameplay, false, "Skip death animation"});
    m_toggles.push_back({"instant_respawn", "Instant Respawn", ToggleCategory::Gameplay, false, "Respawn fast"});
    m_toggles.push_back({"checkpoint_anywhere", "Checkpoint Anywhere", ToggleCategory::Practice, false, "Place checkpoints"});
    m_toggles.push_back({"rainbow_cube", "Rainbow Cube", ToggleCategory::Visual, false, "Rainbow colors"});
    m_toggles.push_back({"cube_always", "Cube Always", ToggleCategory::Movement, false, "Stay cube"});
    m_toggles.push_back({"perfect_timing", "Perfect Timing", ToggleCategory::Gameplay, false, "Perfect inputs"});
    m_toggles.push_back({"instant_portal", "Instant Portal", ToggleCategory::Gameplay, false, "Teleport instantly"});
    m_toggles.push_back({"phase_through", "Phase Through", ToggleCategory::Movement, false, "Ghost mode"});
    m_toggles.push_back({"double_jump", "Double Jump", ToggleCategory::Movement, false, "Jump twice"});
    m_toggles.push_back({"triple_jump", "Triple Jump", ToggleCategory::Movement, false, "Jump three times"});
    m_toggles.push_back({"wall_jump", "Wall Jump", ToggleCategory::Movement, false, "Jump off walls"});
    m_toggles.push_back({"dash_ability", "Dash Ability", ToggleCategory::Movement, false, "Dash forward"});
    m_toggles.push_back({"time_manipulation", "Time Manipulation", ToggleCategory::Gameplay, false, "Control time"});
    m_toggles.push_back({"mega_gravity", "Mega Gravity", ToggleCategory::Gameplay, false, "Extreme gravity"});
    m_toggles.push_back({"anti_gravity", "Anti Gravity", ToggleCategory::Gameplay, false, "Reverse gravity"});
    m_toggles.push_back({"one_hit_wonder", "One Hit Mode", ToggleCategory::Gameplay, false, "One hit to win"});
    m_toggles.push_back({"no_wave_segment", "Skip Wave", ToggleCategory::Gameplay, false, "Skip wave mode"});
    m_toggles.push_back({"no_ball_segment", "Skip Ball", ToggleCategory::Gameplay, false, "Skip ball mode"});

    // MOVEMENT TOGGLES (25 toggles)
    m_toggles.push_back({"gravity_off", "Gravity Off", ToggleCategory::Movement, false, "No gravity"});
    m_toggles.push_back({"low_gravity", "Low Gravity", ToggleCategory::Movement, false, "Less gravity"});
    m_toggles.push_back({"high_gravity", "High Gravity", ToggleCategory::Movement, false, "More gravity"});
    m_toggles.push_back({"no_ship_segment", "Skip Ship", ToggleCategory::Movement, false, "Skip ship mode"});
    m_toggles.push_back({"no_ufo_segment", "Skip UFO", ToggleCategory::Movement, false, "Skip UFO mode"});
    m_toggles.push_back({"no_spider_segment", "Skip Spider", ToggleCategory::Movement, false, "Skip spider mode"});
    m_toggles.push_back({"no_swing_segment", "Skip Swing", ToggleCategory::Movement, false, "Skip swing mode"});
    m_toggles.push_back({"air_dash", "Air Dash", ToggleCategory::Movement, false, "Dash in air"});
    m_toggles.push_back({"ground_dash", "Ground Dash", ToggleCategory::Movement, false, "Dash on ground"});
    m_toggles.push_back({"momentum_control", "Momentum Control", ToggleCategory::Movement, false, "Control momentum"});
    m_toggles.push_back({"friction_off", "Friction Off", ToggleCategory::Movement, false, "No friction"});
    m_toggles.push_back({"slide_boost", "Slide Boost", ToggleCategory::Movement, false, "Boost on slide"});
    m_toggles.push_back({"wall_slide", "Wall Slide", ToggleCategory::Movement, false, "Slide on walls"});
    m_toggles.push_back({"air_control", "Air Control", ToggleCategory::Movement, false, "Control in air"});
    m_toggles.push_back({"instant_velocity", "Instant Velocity", ToggleCategory::Movement, false, "Max speed instantly"});
    m_toggles.push_back({"knockback_resist", "Knockback Resist", ToggleCategory::Movement, false, "Resist knockback"});
    m_toggles.push_back({"bounce_control", "Bounce Control", ToggleCategory::Movement, false, "Control bounces"});
    m_toggles.push_back({"directional_control", "Directional Control", ToggleCategory::Movement, false, "Full movement control"});
    m_toggles.push_back({"swim_mode", "Swim Mode", ToggleCategory::Movement, false, "Swim mechanics"});
    m_toggles.push_back({"climb_walls", "Climb Walls", ToggleCategory::Movement, false, "Climb any wall"});
    m_toggles.push_back({"teleport_jump", "Teleport Jump", ToggleCategory::Movement, false, "Teleport on jump"});
    m_toggles.push_back({"speed_burst", "Speed Burst", ToggleCategory::Movement, false, "Quick speed boost"});
    m_toggles.push_back({"velocity_lock", "Velocity Lock", ToggleCategory::Movement, false, "Lock velocity"});
    m_toggles.push_back({"acceleration_boost", "Acceleration Boost", ToggleCategory::Movement, false, "Faster acceleration"});
    m_toggles.push_back({"deceleration_control", "Deceleration Control", ToggleCategory::Movement, false, "Slower deceleration"});

    // VISUAL TOGGLES (35 toggles)
    m_toggles.push_back({"hide_ui", "Hide UI", ToggleCategory::HUD, false, "Hide all UI"});
    m_toggles.push_back({"hide_hud", "Hide HUD", ToggleCategory::HUD, false, "Hide HUD"});
    m_toggles.push_back({"hide_pause_button", "Hide Pause Button", ToggleCategory::HUD, false, "Hide pause"});
    m_toggles.push_back({"practice_button_gone", "Practice Button Gone", ToggleCategory::HUD, false, "No practice"});
    m_toggles.push_back({"hide_score", "Hide Score", ToggleCategory::HUD, false, "No score shown"});
    m_toggles.push_back({"hide_percentage", "Hide Percentage", ToggleCategory::HUD, false, "No percent shown"});
    m_toggles.push_back({"hide_fps", "Hide FPS", ToggleCategory::HUD, false, "Hide FPS counter"});
    m_toggles.push_back({"hide_spikes", "Hide Spikes", ToggleCategory::Visual, false, "Invisible spikes"});
    m_toggles.push_back({"hide_platforms", "Hide Platforms", ToggleCategory::Visual, false, "Invisible platforms"});
    m_toggles.push_back({"hide_enemies", "Hide Enemies", ToggleCategory::Visual, false, "Invisible enemies"});
    m_toggles.push_back({"hide_background", "Hide Background", ToggleCategory::Visual, false, "No background"});
    m_toggles.push_back({"hide_particles", "Hide Particles", ToggleCategory::Visual, false, "No particles"});
    m_toggles.push_back({"hide_objects", "Hide Objects", ToggleCategory::Visual, false, "No objects"});
    m_toggles.push_back({"hide_ground", "Hide Ground", ToggleCategory::Visual, false, "Invisible ground"});
    m_toggles.push_back({"hide_player", "Hide Player", ToggleCategory::Visual, false, "Invisible player"});
    m_toggles.push_back({"transparent_player", "Transparent Player", ToggleCategory::Visual, false, "See-through"});
    m_toggles.push_back({"glow_player", "Glow Player", ToggleCategory::Visual, false, "Glowing player"});
    m_toggles.push_back({"rainbow_player", "Rainbow Player", ToggleCategory::Visual, false, "Rainbow player"});
    m_toggles.push_back({"neon_player", "Neon Player", ToggleCategory::Visual, false, "Neon glow"});
    m_toggles.push_back({"giant_player", "Giant Player", ToggleCategory::Visual, false, "Big player"});
    m_toggles.push_back({"tiny_player", "Tiny Player", ToggleCategory::Visual, false, "Small player"});
    m_toggles.push_back({"hide_trail", "Hide Trail", ToggleCategory::Visual, false, "No trail"});
    m_toggles.push_back({"rainbow_trail", "Rainbow Trail", ToggleCategory::Visual, false, "Rainbow trail"});
    m_toggles.push_back({"thick_trail", "Thick Trail", ToggleCategory::Visual, false, "Thick trail"});
    m_toggles.push_back({"hide_effects", "Hide Effects", ToggleCategory::Visual, false, "No effects"});
    m_toggles.push_back({"hide_shadows", "Hide Shadows", ToggleCategory::Visual, false, "No shadows"});
    m_toggles.push_back({"show_hitbox", "Show Hitbox", ToggleCategory::Visual, false, "See hitbox"});
    m_toggles.push_back({"dark_mode", "Dark Mode", ToggleCategory::Visual, false, "Dark theme"});
    m_toggles.push_back({"light_mode", "Light Mode", ToggleCategory::Visual, false, "Light theme"});
    m_toggles.push_back({"grayscale_mode", "Grayscale Mode", ToggleCategory::Visual, false, "Black and white"});
    m_toggles.push_back({"high_contrast", "High Contrast", ToggleCategory::Visual, false, "More contrast"});
    m_toggles.push_back({"inverted_colors", "Inverted Colors", ToggleCategory::Visual, false, "Inverted"});
    m_toggles.push_back({"sepia_mode", "Sepia Mode", ToggleCategory::Visual, false, "Sepia tone"});
    m_toggles.push_back({"neon_mode", "Neon Mode", ToggleCategory::Visual, false, "Neon colors"});
    m_toggles.push_back({"retro_mode", "Retro Mode", ToggleCategory::Visual, false, "8-bit style"});

    // SPEED TOGGLES (20 toggles)
    m_toggles.push_back({"speed_1x", "Speed 1x", ToggleCategory::Speed, false, "Normal speed"});
    m_toggles.push_back({"speed_2x", "Speed 2x", ToggleCategory::Speed, false, "Double speed"});
    m_toggles.push_back({"speed_05x", "Speed 0.5x", ToggleCategory::Speed, false, "Half speed"});
    m_toggles.push_back({"speed_3x", "Speed 3x", ToggleCategory::Speed, false, "Triple speed"});
    m_toggles.push_back({"speed_4x", "Speed 4x", ToggleCategory::Speed, false, "Quad speed"});
    m_toggles.push_back({"speed_025x", "Speed 0.25x", ToggleCategory::Speed, false, "Quarter speed"});
    m_toggles.push_back({"speed_custom", "Custom Speed", ToggleCategory::Speed, false, "Custom value"});
    m_toggles.push_back({"speed_ramp", "Speed Ramp", ToggleCategory::Speed, false, "Gradual speed change"});
    m_toggles.push_back({"speed_boost", "Speed Boost", ToggleCategory::Speed, false, "Temporary speed"});
    m_toggles.push_back({"speed_decay", "Speed Decay", ToggleCategory::Speed, false, "Gradual slowdown"});
    m_toggles.push_back({"animation_speed", "Animation Speed", ToggleCategory::Speed, false, "Faster animations"});
    m_toggles.push_back({"physics_speed", "Physics Speed", ToggleCategory::Speed, false, "Faster physics"});
    m_toggles.push_back({"particle_speed", "Particle Speed", ToggleCategory::Speed, false, "Faster particles"});
    m_toggles.push_back({"scroll_speed", "Scroll Speed", ToggleCategory::Speed, false, "Faster scrolling"});
    m_toggles.push_back({"fall_speed", "Fall Speed", ToggleCategory::Speed, false, "Faster falling"});
    m_toggles.push_back({"jump_speed", "Jump Speed", ToggleCategory::Speed, false, "Faster jumping"});
    m_toggles.push_back({"rotation_speed", "Rotation Speed", ToggleCategory::Speed, false, "Faster rotation"});
    m_toggles.push_back({"flip_speed", "Flip Speed", ToggleCategory::Speed, false, "Faster flips"});
    m_toggles.push_back({"movement_speed", "Movement Speed", ToggleCategory::Speed, false, "Faster movement"});
    m_toggles.push_back({"action_speed", "Action Speed", ToggleCategory::Speed, false, "Faster actions"});

    // PRACTICE TOGGLES (15 toggles)
    m_toggles.push_back({"checkpoint_save", "Checkpoint Save", ToggleCategory::Practice, false, "Save at checkpoints"});
    m_toggles.push_back({"infinite_attempts", "Infinite Attempts", ToggleCategory::Practice, false, "Unlimited tries"});
    m_toggles.push_back({"death_counter", "Death Counter", ToggleCategory::Practice, false, "Count deaths"});
    m_toggles.push_back({"timer_display", "Timer Display", ToggleCategory::Practice, false, "Show timer"});
    m_toggles.push_back({"ghost_recording", "Ghost Recording", ToggleCategory::Practice, false, "Record playback"});
    m_toggles.push_back({"ghost_playback", "Ghost Playback", ToggleCategory::Practice, false, "Play recordings"});
    m_toggles.push_back({"split_timer", "Split Timer", ToggleCategory::Practice, false, "Segment timing"});
    m_toggles.push_back({"marker_placement", "Marker Placement", ToggleCategory::Practice, false, "Place markers"});
    m_toggles.push_back({"attempt_save", "Attempt Save", ToggleCategory::Practice, false, "Save attempts"});
    m_toggles.push_back({"replay_mode", "Replay Mode", ToggleCategory::Practice, false, "Replay attempts"});
    m_toggles.push_back({"segment_jump", "Segment Jump", ToggleCategory::Practice, false, "Jump to segments"});
    m_toggles.push_back({"practice_speed", "Practice Speed", ToggleCategory::Practice, false, "Adjust speed in practice"});
    m_toggles.push_back({"practice_restart", "Practice Restart", ToggleCategory::Practice, false, "Quick restart"});
    m_toggles.push_back({"practice_checkpoint", "Practice Checkpoint", ToggleCategory::Practice, false, "Save checkpoints"});
    m_toggles.push_back({"practice_rewind", "Practice Rewind", ToggleCategory::Practice, false, "Rewind gameplay"});

    // UTILITY TOGGLES (20 toggles)
    m_toggles.push_back({"auto_save", "Auto Save", ToggleCategory::Utility, false, "Auto save progress"});
    m_toggles.push_back({"quick_restart", "Quick Restart", ToggleCategory::Utility, false, "Fast level restart"});
    m_toggles.push_back({"level_skip", "Level Skip", ToggleCategory::Utility, false, "Skip levels"});
    m_toggles.push_back({"free_play", "Free Play", ToggleCategory::Utility, false, "Play freely"});
    m_toggles.push_back({"sandbox_mode", "Sandbox Mode", ToggleCategory::Utility, false, "Create freely"});
    m_toggles.push_back({"editor_mode", "Editor Mode", ToggleCategory::Utility, false, "Open editor"});
    m_toggles.push_back({"noclip_editor", "NoClip Editor", ToggleCategory::Utility, false, "NoClip in editor"});
    m_toggles.push_back({"object_spawn", "Object Spawn", ToggleCategory::Utility, false, "Spawn objects"});
    m_toggles.push_back({"object_delete", "Object Delete", ToggleCategory::Utility, false, "Delete objects"});
    m_toggles.push_back({"camera_tools", "Camera Tools", ToggleCategory::Utility, false, "Camera control"});
    m_toggles.push_back({"grid_snap", "Grid Snap", ToggleCategory::Utility, false, "Snap to grid"});
    m_toggles.push_back({"copy_objects", "Copy Objects", ToggleCategory::Utility, false, "Duplicate objects"});
    m_toggles.push_back({"paste_objects", "Paste Objects", ToggleCategory::Utility, false, "Paste objects"});
    m_toggles.push_back({"undo_redo", "Undo/Redo", ToggleCategory::Utility, false, "Undo and redo"});
    m_toggles.push_back({"layer_control", "Layer Control", ToggleCategory::Utility, false, "Manage layers"});
    m_toggles.push_back({"group_objects", "Group Objects", ToggleCategory::Utility, false, "Group items"});
    m_toggles.push_back({"color_palette", "Color Palette", ToggleCategory::Utility, false, "Change colors"});
    m_toggles.push_back({"effect_editor", "Effect Editor", ToggleCategory::Utility, false, "Edit effects"});
    m_toggles.push_back({"property_panel", "Property Panel", ToggleCategory::Utility, false, "Object properties"});
    m_toggles.push_back({"advanced_tools", "Advanced Tools", ToggleCategory::Utility, false, "Pro tools"});

    // AUDIO TOGGLES (10 toggles)
    m_toggles.push_back({"mute_all", "Mute All", ToggleCategory::Audio, false, "Silence everything"});
    m_toggles.push_back({"mute_music", "Mute Music", ToggleCategory::Audio, false, "No background music"});
    m_toggles.push_back({"mute_sfx", "Mute SFX", ToggleCategory::Audio, false, "No sound effects"});
    m_toggles.push_back({"volume_control", "Volume Control", ToggleCategory::Audio, false, "Adjust volume"});
    m_toggles.push_back({"sound_eq", "Sound EQ", ToggleCategory::Audio, false, "Equalizer"});
    m_toggles.push_back({"surround_sound", "Surround Sound", ToggleCategory::Audio, false, "3D audio"});
    m_toggles.push_back({"audio_reverse", "Audio Reverse", ToggleCategory::Audio, false, "Reverse audio"});
    m_toggles.push_back({"audio_pitch", "Audio Pitch", ToggleCategory::Audio, false, "Change pitch"});
    m_toggles.push_back({"audio_loop", "Audio Loop", ToggleCategory::Audio, false, "Loop audio"});
    m_toggles.push_back({"audio_fade", "Audio Fade", ToggleCategory::Audio, false, "Fade audio"});

    // BOTS TOGGLES (15 toggles)
    m_toggles.push_back({"click_bot", "Click Bot", ToggleCategory::Bots, false, "Auto clicker"});
    m_toggles.push_back({"macro_bot", "Macro Bot", ToggleCategory::Bots, false, "Record macros"});
    m_toggles.push_back({"ai_bot", "AI Bot", ToggleCategory::Bots, false, "AI player"});
    m_toggles.push_back({"physics_bot", "Physics Bot", ToggleCategory::Bots, false, "Physics simulation"});
    m_toggles.push_back({"perfect_bot", "Perfect Bot", ToggleCategory::Bots, false, "Perfect runs"});
    m_toggles.push_back({"timing_bot", "Timing Bot", ToggleCategory::Bots, false, "Perfect timing"});
    m_toggles.push_back({"path_finder", "Path Finder", ToggleCategory::Bots, false, "Path planning"});
    m_toggles.push_back({"collision_avoid", "Collision Avoid", ToggleCategory::Bots, false, "Avoid obstacles"});
    m_toggles.push_back({"speed_runner", "Speed Runner", ToggleCategory::Bots, false, "Fast completion"});
    m_toggles.push_back({"precision_mode", "Precision Mode", ToggleCategory::Bots, false, "Precise control"});
    m_toggles.push_back({"replay_bot", "Replay Bot", ToggleCategory::Bots, false, "Replay recordings"});
    m_toggles.push_back({"random_bot", "Random Bot", ToggleCategory::Bots, false, "Random actions"});
    m_toggles.push_back({"learning_bot", "Learning Bot", ToggleCategory::Bots, false, "Adaptive AI"});
    m_toggles.push_back({"multi_bot", "Multi Bot", ToggleCategory::Bots, false, "Multiple bots"});
    m_toggles.push_back({"bot_recorder", "Bot Recorder", ToggleCategory::Bots, false, "Record bot inputs"});

    // PC limit: 160 toggles (all above = 245 total)
    // Mobile: 200 toggles (all above except last 45)
}

ToggleEntry* ToggleManager::find(const std::string& id) {
    for (auto& toggle : m_toggles) {
        if (toggle.id == id) {
            return &toggle;
        }
    }
    return nullptr;
}

void ToggleManager::set(const std::string& id, bool state) {
    auto* toggle = find(id);
    if (toggle) {
        toggle->enabled = state;
    }
}

bool ToggleManager::get(const std::string& id) const {
    for (const auto& toggle : m_toggles) {
        if (toggle.id == id) {
            return toggle.enabled;
        }
    }
    return false;
}

const std::vector<ToggleEntry>& ToggleManager::all() const {
    return m_toggles;
}

std::vector<ToggleEntry> ToggleManager::getByCategory(ToggleCategory cat) const {
    std::vector<ToggleEntry> result;
    for (const auto& toggle : m_toggles) {
        if (toggle.category == cat) {
            result.push_back(toggle);
        }
    }
    return result;
}

void ToggleManager::saveSettings() {
    // Save to Geode config
    auto config = Mod::get()->getSavedValue<std::string>("gravity_settings", "");
    // Implementation for saving
}

void ToggleManager::loadSettings() {
    // Load from Geode config
    auto config = Mod::get()->getSavedValue<std::string>("gravity_settings", "");
    // Implementation for loading
}

// THEME MANAGER
ThemeManager& ThemeManager::get() {
    static ThemeManager instance;
    return instance;
}

void ThemeManager::initMobileThemes() {
    m_isMobileTheme = true;
    m_themes.clear();

    // 50 Mobile Themes
    m_themes.push_back({"crimson", "Crimson", "#DC143C", "#8B0000", "#FF1744", "#FFFFFF"});
    m_themes.push_back({"emerald", "Emerald", "#50C878", "#228B22", "#00FF41", "#FFFFFF"});
    m_themes.push_back({"sapphire", "Sapphire", "#0F52BA", "#000080", "#1E90FF", "#FFFFFF"});
    m_themes.push_back({"neon_cyan", "Neon Cyan", "#00FFFF", "#00CED1", "#00FFFF", "#000000"});
    m_themes.push_back({"gold", "Gold", "#FFD700", "#FFA500", "#FFFF00", "#000000"});
    m_themes.push_back({"purple_pulse", "Purple Pulse", "#9D00FF", "#6A0DAD", "#DA70D6", "#FFFFFF"});
    m_themes.push_back({"sunset", "Sunset", "#FF6347", "#FF8C00", "#FFD700", "#FFFFFF"});
    m_themes.push_back({"midnight", "Midnight", "#0A0E27", "#1A1A3E", "#4B0082", "#FFFFFF"});
    m_themes.push_back({"matrix", "Matrix", "#000000", "#001A00", "#00FF00", "#00FF00"});
    m_themes.push_back({"ghost_white", "Ghost White", "#F8F8FF", "#E8E8FF", "#B0C4DE", "#000000"});
    m_themes.push_back({"dark_blue", "Dark Blue", "#00008B", "#000033", "#4169E1", "#FFFFFF"});
    m_themes.push_back({"coral", "Coral", "#FF7F50", "#FF6347", "#FFB6C1", "#FFFFFF"});
    m_themes.push_back({"aqua", "Aqua", "#00FFFF", "#00CED1", "#87CEEB", "#000000"});
    m_themes.push_back({"lime", "Lime", "#00FF00", "#32CD32", "#90EE90", "#000000"});
    m_themes.push_back({"rose", "Rose", "#FF007F", "#C71585", "#FFB6C1", "#FFFFFF"});
    m_themes.push_back({"violet", "Violet", "#EE82EE", "#8B008B", "#DA70D6", "#FFFFFF"});
    m_themes.push_back({"orange", "Orange", "#FF8C00", "#FF6347", "#FFD700", "#FFFFFF"});
    m_themes.push_back({"ice", "Ice", "#B0E0E6", "#87CEEB", "#00FFFF", "#000000"});
    m_themes.push_back({"lava", "Lava", "#FF4500", "#8B0000", "#FFD700", "#FFFFFF"});
    m_themes.push_back({"arctic", "Arctic", "#E0FFFF", "#B0E0E6", "#00CED1", "#000080"});
    m_themes.push_back({"electric", "Electric", "#FFFF00", "#00FFFF", "#FF00FF", "#000000"});
    m_themes.push_back({"plasma", "Plasma", "#FF1493", "#00FFFF", "#FF00FF", "#FFFFFF"});
    m_themes.push_back({"forest", "Forest", "#228B22", "#006400", "#7CB342", "#FFFFFF"});
    m_themes.push_back({"space", "Space", "#191970", "#000033", "#4B0082", "#FFFFFF"});
    m_themes.push_back({"pink", "Pink", "#FF69B4", "#FF1493", "#FFB6C1", "#FFFFFF"});
    m_themes.push_back({"red", "Red", "#FF0000", "#8B0000", "#FF6347", "#FFFFFF"});
    m_themes.push_back({"blue", "Blue", "#0000FF", "#000080", "#1E90FF", "#FFFFFF"});
    m_themes.push_back({"green", "Green", "#008000", "#006400", "#00FF00", "#FFFFFF"});
    m_themes.push_back({"yellow", "Yellow", "#FFFF00", "#FFD700", "#FFA500", "#000000"});
    m_themes.push_back({"magenta", "Magenta", "#FF00FF", "#C71585", "#DA70D6", "#FFFFFF"});
    m_themes.push_back({"rainbow", "Rainbow", "#FF0000", "#00FF00", "#0000FF", "#FFFFFF"});
    m_themes.push_back({"steam", "Steam", "#1B2838", "#2A475E", "#1790FF", "#FFFFFF"});
    m_themes.push_back({"moonlight", "Moonlight", "#0C1821", "#1A1A2E", "#16213E", "#E0E0FF"});
    m_themes.push_back({"shadow", "Shadow", "#2F2F2F", "#1A1A1A", "#404040", "#FFFFFF"});
    m_themes.push_back({"heatwave", "Heatwave", "#FF0000", "#FF4500", "#FFD700", "#FFFFFF"});
    m_themes.push_back({"flash", "Flash", "#FFFF00", "#FFA500", "#FF6347", "#000000"});
    m_themes.push_back({"holo", "Holo", "#00FFFF", "#FF00FF", "#FFFF00", "#000000"});
    m_themes.push_back({"chrome", "Chrome", "#C0C0C0", "#808080", "#FFFFFF", "#000000"});
    m_themes.push_back({"frosted", "Frosted", "#E6F2FF", "#D0E0FF", "#B0D0FF", "#333333"});
    m_themes.push_back({"soft_gray", "Soft Gray", "#A9A9A9", "#808080", "#D3D3D3", "#1C1C1C"});
    m_themes.push_back({"dark_gold", "Dark Gold", "#B8860B", "#8B6914", "#DAA520", "#FFFFFF"});
    m_themes.push_back({"cyber", "Cyber", "#0D0221", "#3A86FF", "#FB5607", "#FFFFFF"});
    m_themes.push_back({"obsidian", "Obsidian", "#0F0F0F", "#1A1A1A", "#333333", "#FFFFFF"});
    m_themes.push_back({"neon_pink", "Neon Pink", "#FF10F0", "#FF006E", "#FF10F0", "#FFFFFF"});
    m_themes.push_back({"neon_green", "Neon Green", "#39FF14", "#0FFF50", "#39FF14", "#000000"});
    m_themes.push_back({"neon_blue", "Neon Blue", "#00D9FF", "#0080FF", "#00D9FF", "#FFFFFF"});
    m_themes.push_back({"candy", "Candy", "#FF69B4", "#FFB6C1", "#FFC0CB", "#000000"});
    m_themes.push_back({"ocean", "Ocean", "#006994", "#0099CC", "#00CCFF", "#FFFFFF"});
    m_themes.push_back({"volcano", "Volcano", "#8B4513", "#D2691E", "#FF4500", "#FFFFFF"});
    m_themes.push_back({"cyber_pink", "Cyber Pink", "#FF006E", "#FB5607", "#FFBE0B", "#FFFFFF"});
}

void ThemeManager::initPCThemes() {
    m_isMobileTheme = false;
    m_themes.clear();

    // 35 PC Themes
    m_themes.push_back({"classic_megahack", "Classic MegaHack", "#1E1E1E", "#2D2D30", "#007ACC", "#CCCCCC"});
    m_themes.push_back({"modern_ui", "Modern UI", "#FFFFFF", "#F3F3F3", "#0078D4", "#000000"});
    m_themes.push_back({"dark_mode", "Dark Mode", "#1E1E1E", "#252526", "#007ACC", "#E0E0E0"});
    m_themes.push_back({"light_mode", "Light Mode", "#FFFFFF", "#F0F0F0", "#0078D4", "#333333"});
    m_themes.push_back({"neon_bright", "Neon Bright", "#000000", "#1A1A1A", "#00FF00", "#00FF00"});
    m_themes.push_back({"midnight_blue", "Midnight Blue", "#0A1428", "#1C2D3C", "#0D47A1", "#E0E0E0"});
    m_themes.push_back({"cyber_purple", "Cyber Purple", "#2D0A3E", "#3D1A4E", "#9D4EDD", "#E0E0E0"});
    m_themes.push_back({"hacker_green", "Hacker Green", "#0F0F0F", "#1A1A1A", "#00FF00", "#00FF00"});
    m_themes.push_back({"sunset_orange", "Sunset Orange", "#3D2817", "#5C3D2E", "#FF6B35", "#F5E6D3"});
    m_themes.push_back({"ice_blue", "Ice Blue", "#E0F7FF", "#D0F0FF", "#0099CC", "#000000"});
    m_themes.push_back({"deep_purple", "Deep Purple", "#1A0033", "#330066", "#9900FF", "#E6E6FF"});
    m_themes.push_back({"forest_green", "Forest Green", "#0B3D2C", "#1A6B52", "#2ECC71", "#FFFFFF"});
    m_themes.push_back({"blood_red", "Blood Red", "#330000", "#660000", "#FF3333", "#FFFFFF"});
    m_themes.push_back({"slate_gray", "Slate Gray", "#2C3E50", "#34495E", "#3498DB", "#ECF0F1"});
    m_themes.push_back({"golden_brown", "Golden Brown", "#3E2723", "#5D4037", "#FFB74D", "#FFF9E6"});
    m_themes.push_back({"rose_gold", "Rose Gold", "#4A2C2A", "#6D4C4C", "#F4A6A6", "#FFEAEA"});
    m_themes.push_back({"teal_accent", "Teal Accent", "#004D4D", "#1A7A7A", "#00CCCC", "#E0FFFF"});
    m_themes.push_back({"indigo_night", "Indigo Night", "#1A0033", "#2D1B4E", "#6A3BA0", "#D9B3FF"});
    m_themes.push_back({"coral_reef", "Coral Reef", "#332A2A", "#664D4D", "#FF6B6B", "#FFD9D9"});
    m_themes.push_back({"mint_fresh", "Mint Fresh", "#F0FFF0", "#E0F5E0", "#00AA55", "#003322"});
    m_themes.push_back({"lavender_dream", "Lavender Dream", "#F3E5F5", "#E1BEE7", "#7B1FA2", "#4A148C"});
    m_themes.push_back({"charcoal", "Charcoal", "#36454F", "#4F5959", "#8B9DC3", "#FFFFFF"});
    m_themes.push_back({"emerald_pro", "Emerald Pro", "#0D3B2F", "#1A5C52", "#28A74A", "#E8F5E8"});
    m_themes.push_back({"amethyst", "Amethyst", "#3D1C3D", "#6B3B6B", "#CC66FF", "#F0E6F0"});
    m_themes.push_back({"crimson_dark", "Crimson Dark", "#330011", "#660022", "#FF3366", "#FFE6EE"});
    m_themes.push_back({"sapphire_pro", "Sapphire Pro", "#001A33", "#003366", "#0066FF", "#E6F0FF"});
    m_themes.push_back({"obsidian_black", "Obsidian Black", "#0A0A0A", "#1F1F1F", "#404040", "#FFFFFF"});
    m_themes.push_back({"pearl_white", "Pearl White", "#FFFBF5", "#F5F1E8", "#333333", "#1A1A1A"});
    m_themes.push_back({"bronze_metal", "Bronze Metal", "#3E2723", "#5D4037", "#CD7F32", "#FFE5CC"});
    m_themes.push_back({"neon_orange", "Neon Orange", "#000000", "#1A1A1A", "#FF6600", "#FF6600"});
    m_themes.push_back({"neon_yellow", "Neon Yellow", "#000000", "#1A1A1A", "#FFFF00", "#FFFF00"});
    m_themes.push_back({"neon_purple", "Neon Purple", "#000000", "#1A1A1A", "#FF00FF", "#FF00FF"});
    m_themes.push_back({"neon_cyan", "Neon Cyan", "#000000", "#1A1A1A", "#00FFFF", "#00FFFF"});
    m_themes.push_back({"matrix_code", "Matrix Code", "#000000", "#001A00", "#00FF00", "#00FF00"});
    m_themes.push_back({"retro_crt", "Retro CRT", "#1A1A1A", "#2D2D2D", "#CCFF00", "#99CC00"});
}

const std::vector<InterfaceTheme>& ThemeManager::getAllThemes() const {
    return m_themes;
}

const InterfaceTheme& ThemeManager::getTheme(size_t index) const {
    if (index < m_themes.size()) {
        return m_themes[index];
    }
    return m_themes[0]; // Return default if index out of range
}

const InterfaceTheme& ThemeManager::getThemeById(const std::string& id) const {
    for (const auto& theme : m_themes) {
        if (theme.id == id) {
            return theme;
        }
    }
    return m_themes[0]; // Return default
}

void ThemeManager::setCurrentTheme(size_t index) {
    if (index < m_themes.size()) {
        m_currentTheme = index;
    }
}
