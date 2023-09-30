// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#pragma once

#include <services/serviceman.h>

namespace skyline::service::hosbinder {
    class IHOSBinderDriver;
}

namespace skyline::service::am {
    /**
     * @brief This has functions relating to an application's own current status
     * @url https://switchbrew.org/wiki/Applet_Manager_services#ISelfController
     */
    class ISelfController : public BaseService {
      private:
        std::shared_ptr<kernel::type::KEvent> libraryAppletLaunchableEvent; //!< This KEvent is triggered when the library applet is launchable
        std::shared_ptr<kernel::type::KEvent> accumulatedSuspendedTickChangedEvent; //!< This KEvent is triggered when the time the system has spent in suspend is updated
        std::shared_ptr<hosbinder::IHOSBinderDriver> hosbinder; //!< IHOSBinder service for managed display layers
        u32 idleTimeDetectionExtension{0};

        bool autoSleepDisabled{false};

      public:
        ISelfController(const DeviceState &state, ServiceManager &manager);

        /**
         * @brief Exits the current applet
         * @url https://switchbrew.org/wiki/Applet_Manager_services#Exit
         */
        Result Exit(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Function prevents the running application from being quit via the home button
         * @url https://switchbrew.org/wiki/Applet_Manager_services#LockExit
         */
        Result LockExit(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Function allows the running application to be quit via the home button
         * @url https://switchbrew.org/wiki/Applet_Manager_services#UnlockExit
         */
        Result UnlockExit(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Function obtains a handle to the library applet launchable event
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetLibraryAppletLaunchableEvent
         */
        Result GetLibraryAppletLaunchableEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetScreenShotPermission
         */
        Result SetScreenShotPermission(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief This function takes a u8 bool flag and no output (Stubbed)
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetOperationModeChangedNotification
         */
        Result SetOperationModeChangedNotification(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief This function takes a u8 bool flag and no output (Stubbed)
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetPerformanceModeChangedNotification
         */
        Result SetPerformanceModeChangedNotification(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief This function takes 3 unknown u8 values and has no output (Stubbed)
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetCurrentFocusState
         */
        Result SetFocusHandlingMode(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Toggles whether a restart message should be sent or not
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetRestartMessageEnabled
         */
        Result SetRestartMessageEnabled(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief This function takes a u8 bool flag and has no output (Stubbed)
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetOutOfFocusSuspendingEnabled
         */
        Result SetOutOfFocusSuspendingEnabled(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetAlbumImageOrientation
         */
        Result SetAlbumImageOrientation(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Returns an output u64 LayerId
         * @url https://switchbrew.org/wiki/Applet_Manager_services#CreateManagedDisplayLayer
         */
        Result CreateManagedDisplayLayer(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetIdleTimeDetectionExtension
         */
        Result SetIdleTimeDetectionExtension(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetIdleTimeDetectionExtension
         */
        Result GetIdleTimeDetectionExtension(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#ReportUserIsActive
         */
        Result ReportUserIsActive(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#IsIlluminanceAvailable
         */
        Result IsIlluminanceAvailable(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetAutoSleepDisabled
         */
        Result SetAutoSleepDisabled(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#IsAutoSleepDisabled
         */
        Result IsAutoSleepDisabled(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetCurrentIlluminanceEx
         */
        Result GetCurrentIlluminanceEx(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Returns how long the process was suspended for in ticks
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetAccumulatedSuspendedTickValue
         */
        Result GetAccumulatedSuspendedTickValue(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @brief Returns a handle to a KEvent that is signalled when the accumulated suspend tick value changes
         * @url https://switchbrew.org/wiki/Applet_Manager_services#GetAccumulatedSuspendedTickChangedEvent
         */
        Result GetAccumulatedSuspendedTickChangedEvent(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetAlbumImageTakenNotificationEnabled
         */
        Result SetAlbumImageTakenNotificationEnabled(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        /**
         * @url https://switchbrew.org/wiki/Applet_Manager_services#SetRecordVolumeMuted
         */
        Result SetRecordVolumeMuted(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response);

        SERVICE_DECL(
            SFUNC(0x0, ISelfController, Exit),
            SFUNC(0x1, ISelfController, LockExit),
            SFUNC(0x2, ISelfController, UnlockExit),
            SFUNC(0x9, ISelfController, GetLibraryAppletLaunchableEvent),
            SFUNC(0xA, ISelfController, SetScreenShotPermission),
            SFUNC(0xB, ISelfController, SetOperationModeChangedNotification),
            SFUNC(0xC, ISelfController, SetPerformanceModeChangedNotification),
            SFUNC(0xD, ISelfController, SetFocusHandlingMode),
            SFUNC(0xE, ISelfController, SetRestartMessageEnabled),
            SFUNC(0x10, ISelfController, SetOutOfFocusSuspendingEnabled),
            SFUNC(0x13, ISelfController, SetAlbumImageOrientation),
            SFUNC(0x28, ISelfController, CreateManagedDisplayLayer),
            SFUNC(0x3E, ISelfController, SetIdleTimeDetectionExtension),
            SFUNC(0x3F, ISelfController, GetIdleTimeDetectionExtension),
            SFUNC(0x41, ISelfController, ReportUserIsActive),
            SFUNC(0x43, ISelfController, IsIlluminanceAvailable),
            SFUNC(0x44, ISelfController, SetAutoSleepDisabled),
            SFUNC(0x45, ISelfController, IsAutoSleepDisabled),
            SFUNC(0x47, ISelfController, GetCurrentIlluminanceEx),
            SFUNC(0x5A, ISelfController, GetAccumulatedSuspendedTickValue),
            SFUNC(0x5B, ISelfController, GetAccumulatedSuspendedTickChangedEvent),
            SFUNC(0x64, ISelfController, SetAlbumImageTakenNotificationEnabled),
            SFUNC(0x82, ISelfController, SetRecordVolumeMuted)
        )
    };
}
