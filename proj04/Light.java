package io.githb.coldwellop1.flash;

// import statements for usage in file
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.hardware.Camera;
import android.hardware.Camera.Parameters;
import android.app.*;
import android.os.*;
import android.view.*;
import android.widget.ToggleButton;
import android.util.Log;

public class Light extends Activity
{
    ToggleButton flashButton;
    private Camera camera;
    private boolean statusFlash;  //true = on, false = off.
    private boolean hasFlash;

    Parameters params;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_light);

        // flash switch button
        ToggleButton toggle = (ToggleButton) findViewById(R.id.togglebutton);

        // check if device has (camera) flash
        hasFlash = getApplicationContext().getPackageManager()
                .hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH);

        if (!hasFlash) {
            // no flash
            // Show alert message and exit
            AlertDialog alert = new AlertDialog.Builder(Light.this)
                    .create();
            alert.setTitle("Error");
            alert.setMessage("You don't have a flashlight.");
            alert.setButton("OK", new DialogInterface.OnClickListener() {
                public void onClick(DialogInterface dialog, int which) {
                    // exit
                    finish();
                }
            });
            alert.show();
            return;
        }

        // get the camera
        getCamera();


        // create button click event to recognize switch changes
        toggle.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                if (statusFlash) {
                    turnOffFlash();
                } else {
                    turnOnFlash();
                }
            }
        });
    }


    // Get the camera
    private void getCamera() {
        if (camera == null) {
            try {
                camera = Camera.open();
                params = camera.getParameters();
            } catch (RuntimeException e) {
                Log.e("Error: ", e.getMessage());
            }
        }
    }


    // turn on flash
    private void turnOnFlash() {
        if (!statusFlash) {
            if (camera == null || params == null) {
                return;
            }

            params = camera.getParameters();
            params.setFlashMode(Parameters.FLASH_MODE_TORCH);
            camera.setParameters(params);
            camera.startPreview();
            statusFlash = true;
        }

    }


    // turn off flash
    private void turnOffFlash() {
        if (statusFlash) {
            if (camera == null || params == null) {
                return;
            }

            params = camera.getParameters();
            params.setFlashMode(Parameters.FLASH_MODE_OFF);
            camera.setParameters(params);
            camera.stopPreview();
            statusFlash = false;
        }
    }



// statuses for different states
    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override
    protected void onPause() {
        super.onPause();

        // on pause turn off the flash
        turnOffFlash();
    }

    @Override
    protected void onRestart() {
        super.onRestart();
    }

    @Override
    protected void onResume() {
        super.onResume();

        // on resume turn on the flash
        if(hasFlash)
            turnOnFlash();
    }

    @Override
    protected void onStart() {
        super.onStart();

        // on starting the app get the camera params
        getCamera();
    }

    @Override
    protected void onStop() {
        super.onStop();

        // on stop release the camera
        if (camera != null) {
            camera.release();
            camera = null;
        }
    }

}