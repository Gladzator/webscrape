// This file implements the IBackgroundCopyManager Interface for Python.
// Generated by makegw.py

#include "bits_pch.h"
#include "PyIBackgroundCopyManager.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIBackgroundCopyManager::PyIBackgroundCopyManager(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIBackgroundCopyManager::~PyIBackgroundCopyManager() {}

/* static */ IBackgroundCopyManager *PyIBackgroundCopyManager::GetI(PyObject *self)
{
    return (IBackgroundCopyManager *)PyIUnknown::GetI(self);
}

// @pymethod |PyIBackgroundCopyManager|CreateJob|Description of CreateJob.
PyObject *PyIBackgroundCopyManager::CreateJob(PyObject *self, PyObject *args)
{
    IBackgroundCopyManager *pIBCM = GetI(self);
    if (pIBCM == NULL)
        return NULL;
    // @pyparm <o unicode>|DisplayName||Description for DisplayName
    BG_JOB_TYPE Type;
    // @pyparm int|Type||Job Type (See BG_JOB_TYPE_*)
    GUID pJobId;
    PyObject *obDisplayName;
    LPWSTR DisplayName;
    IBackgroundCopyJob *ppJob;
    if (!PyArg_ParseTuple(args, "Ol:CreateJob", &obDisplayName, &Type))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyWinObject_AsBstr(obDisplayName, &DisplayName))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIBCM->CreateJob(DisplayName, Type, &pJobId, &ppJob);
    SysFreeString(DisplayName);

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIBCM, IID_IBackgroundCopyManager);
    return PyCom_PyObjectFromIUnknown(ppJob, IID_IBackgroundCopyJob, FALSE);
}

// @pymethod |PyIBackgroundCopyManager|GetJob|Description of GetJob.
PyObject *PyIBackgroundCopyManager::GetJob(PyObject *self, PyObject *args)
{
    IBackgroundCopyManager *pIBCM = GetI(self);
    if (pIBCM == NULL)
        return NULL;
    // @pyparm <o PyIID>|jobID||Description for jobID
    PyObject *objobID;
    IID jobID;
    IBackgroundCopyJob *ppJob;
    if (!PyArg_ParseTuple(args, "O:GetJob", &objobID))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsIID(objobID, &jobID))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIBCM->GetJob(jobID, &ppJob);

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIBCM, IID_IBackgroundCopyManager);
    return PyCom_PyObjectFromIUnknown(ppJob, IID_IBackgroundCopyJob, FALSE);
}

// @pymethod |PyIBackgroundCopyManager|EnumJobs|Description of EnumJobs.
PyObject *PyIBackgroundCopyManager::EnumJobs(PyObject *self, PyObject *args)
{
    IBackgroundCopyManager *pIBCM = GetI(self);
    if (pIBCM == NULL)
        return NULL;
    // @pyparm int|dwFlags||Description for dwFlags
    DWORD dwFlags;
    IEnumBackgroundCopyJobs *ppEnum;
    if (!PyArg_ParseTuple(args, "l:EnumJobs", &dwFlags))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIBCM->EnumJobs(dwFlags, &ppEnum);

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIBCM, IID_IBackgroundCopyManager);
    return PyCom_PyObjectFromIUnknown(ppEnum, IID_IEnumBackgroundCopyJobs, FALSE);
}

// @pymethod |PyIBackgroundCopyManager|GetErrorDescription|Description of GetErrorDescription.
PyObject *PyIBackgroundCopyManager::GetErrorDescription(PyObject *self, PyObject *args)
{
    IBackgroundCopyManager *pIBCM = GetI(self);
    if (pIBCM == NULL)
        return NULL;
    // @pyparm int|hResult||Description for hResult
    // @pyparm int|LanguageId||Description for LanguageId
    WCHAR *pszErrorDescription;
    PyObject *obpErrorDescription;
    HRESULT hResult;
    DWORD LanguageId;
    if (!PyArg_ParseTuple(args, "ll:GetErrorDescription", &hResult, &LanguageId))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pIBCM->GetErrorDescription(hResult, LanguageId, &pszErrorDescription);

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pIBCM, IID_IBackgroundCopyManager);

    obpErrorDescription = PyWinObject_FromWCHAR(pszErrorDescription);
    return obpErrorDescription;
}

// @object PyIBackgroundCopyManager|Description of the interface
static struct PyMethodDef PyIBackgroundCopyManager_methods[] = {
    {"CreateJob", PyIBackgroundCopyManager::CreateJob, 1},  // @pymeth CreateJob|Description of CreateJob
    {"GetJob", PyIBackgroundCopyManager::GetJob, 1},        // @pymeth GetJob|Description of GetJob
    {"EnumJobs", PyIBackgroundCopyManager::EnumJobs, 1},    // @pymeth EnumJobs|Description of EnumJobs
    {"GetErrorDescription", PyIBackgroundCopyManager::GetErrorDescription,
     1},  // @pymeth GetErrorDescription|Description of GetErrorDescription
    {NULL}};

PyComTypeObject PyIBackgroundCopyManager::type("PyIBackgroundCopyManager", &PyIUnknown::type,
                                               sizeof(PyIBackgroundCopyManager), PyIBackgroundCopyManager_methods,
                                               GET_PYCOM_CTOR(PyIBackgroundCopyManager));