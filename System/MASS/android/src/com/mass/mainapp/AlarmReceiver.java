package com.mass.mainapp;

import java.text.Format;
import java.text.SimpleDateFormat;
import java.util.Date;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.PowerManager;
import android.widget.Toast;

public class AlarmReceiver extends BroadcastReceiver{

    final public static String ONE_TIME = "onetime";
    PowerManager.WakeLock wl;

@Override
    public void onReceive(Context context, Intent intent)
    {
//        PowerManager pm = (PowerManager) context.getSystemService(Context.POWER_SERVICE);
//        PowerManager.WakeLock wl = pm.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK,"YOUR TAG");
//        //Осуществляем блокировку
//        wl.acquire();

        try
        {
            final PowerManager pm = (PowerManager) context.getSystemService(Context.POWER_SERVICE);

            wl = pm.newWakeLock(PowerManager.SCREEN_DIM_WAKE_LOCK, "My Tag");
            // m_WakeLock = pm.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, "My Tag");
            // Does not work: https://stackoverflow.com/questions/5183859/partial-wake-lock-vs-screen-dim-wake-lock-in-download-thread
            wl.acquire();
        }
        catch (Exception e)
        {
            System.out.println("WakeLock failed: " + e.toString());
        }

        QtActivityExtention.showNotification("MASS alarm test", "Alarm recieved", 1);

//        //Разблокируем поток.
//        wl.release();
    }
}
