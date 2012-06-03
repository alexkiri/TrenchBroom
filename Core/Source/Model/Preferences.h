/*
 Copyright (C) 2010-2012 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_Header_h
#define TrenchBroom_Header_h

#include "Utilities/Event.h"
#include "Utilities/VecMath.h"

namespace TrenchBroom {
    namespace Model {
        class Preferences {
        protected:
            static const std::string CameraKey;
            static const std::string CameraOrbitKey;
            static const std::string CameraInvertY;
            static const std::string CameraFov;
            static const std::string Brightness;
            static const std::string FaceColor;
            static const std::string EdgeColor;
            static const std::string SelectedFaceColor;
            static const std::string SelectedEdgeColor;
            static const std::string HiddenSelectedEdgeColor;
            static const std::string EntityBoundsColor;
            static const std::string EntityBoundsWireframeColor;
            static const std::string SelectedEntityBoundsColor;
            static const std::string HiddenSelectedEntityBoundsColor;
            static const std::string SelectionGuideColor;
            static const std::string HiddenSelectionGuideColor;
            static const std::string BackgroundColor;
            static const std::string InfoOverlayColor;
            static const std::string InfoOverlayFadeDistance;
            static const std::string SelectedInfoOverlayColor;
            static const std::string SelectedInfoOverlayFadeDistance;
            static const std::string SelectedTextureColor;
            static const std::string UsedTextureColor;
            static const std::string OverriddenTextureColor;
            static const std::string RendererFontName;
            static const std::string RendererFontSize;
            static const std::string GridAlpha;
            static const std::string QuakePath;
            
            int m_cameraKey;
            int m_cameraOrbitKey;
            bool m_cameraInvertY;
            
            float m_cameraFov;
            
            float m_brightness;

            Vec4f m_faceColor;
            Vec4f m_edgeColor;
            Vec4f m_selectedFaceColor;
            Vec4f m_selectedEdgeColor;
            Vec4f m_hiddenSelectedEdgeColor;
            Vec4f m_entityBoundsColor;
            Vec4f m_entityBoundsWireframeColor;
            Vec4f m_selectedEntityBoundsColor;
            Vec4f m_hiddenSelectedEntityBoundsColor;
            Vec4f m_selectionGuideColor;
            Vec4f m_hiddenSelectionGuideColor;
            Vec4f m_backgroundColor;
            
            Vec4f m_infoOverlayColor;
            float m_infoOverlayFadeDistance;
            Vec4f m_selectedInfoOverlayColor;
            float m_selectedInfoOverlayFadeDistance;
            
            Vec4f m_selectedTextureColor;
            Vec4f m_usedTextureColor;
            Vec4f m_overriddenTextureColor;
            
            std::string m_rendererFontName;
            int m_rendererFontSize;
            
            float m_gridAlpha;
            
            std::string m_quakePath;

            virtual void loadDefaults();
            virtual void loadPlatformDefaults() = 0;

            virtual bool loadInt(const std::string& key, int& value) = 0;
            virtual bool loadFloat(const std::string& key, float& value) = 0;
            virtual bool loadBool(const std::string& key, bool& value) = 0;
            virtual bool loadString(const std::string& key, std::string& value) = 0;
            virtual bool loadVec4f(const std::string& key, Vec4f& value) = 0;
            void loadPreferences();
            
            virtual void saveInt(const std::string& key, int value) = 0;
            virtual void saveFloat(const std::string& key, float value) = 0;
            virtual void saveBool(const std::string& key, bool value) = 0;
            virtual void saveString(const std::string& key, const std::string& value) = 0;
			virtual void saveVec4f(const std::string& key, const Vec4f& value) = 0;
            virtual bool saveInstantly() = 0;
			void savePreferences();
        public:
            static Preferences* sharedPreferences;

            typedef Event<const std::string&> PreferencesEvent;
            PreferencesEvent preferencesDidChange;
            
            Preferences() {};
            virtual ~Preferences() {};
            
            void init();
			void save();
            
            int cameraKey();
            int cameraOrbitKey();
            bool cameraInvertY();
            void setCameraInvertY(bool cameraInvertY);
            
            float cameraFov();
            void setCameraFov(float cameraFov);
            float cameraNear();
            float cameraFar();
            float brightness();
            void setBrightness(float brightness);
            
            const Vec4f& faceColor();
            const Vec4f& edgeColor();
            const Vec4f& selectedFaceColor();
            const Vec4f& selectedEdgeColor();
            const Vec4f& hiddenSelectedEdgeColor();
            const Vec4f& entityBoundsColor();
            const Vec4f& entityBoundsWireframeColor();
            const Vec4f& selectedEntityBoundsColor();
            const Vec4f& hiddenSelectedEntityBoundsColor();
            const Vec4f& selectionGuideColor();
            const Vec4f& hiddenSelectionGuideColor();
            const Vec4f& backgroundColor();

            const Vec4f& infoOverlayColor();
            float infoOverlayFadeDistance();
            const Vec4f& selectedInfoOverlayColor();
            float selectedInfoOverlayFadeDistance();
            
            const Vec4f& selectedTextureColor();
            const Vec4f& usedTextureColor();
            const Vec4f& overriddenTextureColor();
            
            const std::string& rendererFontName();
            unsigned int rendererFontSize();
            
            float gridAlpha();
            
            const std::string& quakePath();
            void setQuakePath(const std::string& quakePath);
        };
    }
}

#endif
