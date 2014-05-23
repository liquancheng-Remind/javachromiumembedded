// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef CEF_TESTS_CEFCLIENT_REQUEST_HANDLER_H_
#define CEF_TESTS_CEFCLIENT_REQUEST_HANDLER_H_
#pragma once

#include <jni.h>
#include "include/cef_request_handler.h"

// RequestHandler implementation.
class RequestHandler : public CefRequestHandler {
 public:
  RequestHandler(JNIEnv* env, jobject handler);
  virtual ~RequestHandler();

  // CefRequestHandler methods
  virtual bool OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
                              CefRefPtr<CefFrame> frame,
                              CefRefPtr<CefRequest> request,
                              bool is_redirect) OVERRIDE;

  virtual bool OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser,
                                    CefRefPtr<CefFrame> frame,
                                    CefRefPtr<CefRequest> request) OVERRIDE;

  virtual CefRefPtr<CefResourceHandler> GetResourceHandler(
                                    CefRefPtr<CefBrowser> browser,
                                    CefRefPtr<CefFrame> frame,
                                    CefRefPtr<CefRequest> request) OVERRIDE;

  virtual bool GetAuthCredentials(CefRefPtr<CefBrowser> browser,
                                  CefRefPtr<CefFrame> frame,
                                  bool isProxy,
                                  const CefString& host,
                                  int port,
                                  const CefString& realm,
                                  const CefString& scheme,
                                  CefRefPtr<CefAuthCallback> callback) OVERRIDE;

  virtual bool OnQuotaRequest(CefRefPtr<CefBrowser> browser,
                              const CefString& origin_url,
                              int64 new_size,
                              CefRefPtr<CefQuotaCallback> callback) OVERRIDE;

  virtual bool OnCertificateError(
      cef_errorcode_t cert_error,
      const CefString& request_url,
      CefRefPtr<CefAllowCertificateErrorCallback> callback) OVERRIDE;

  virtual void OnRenderProcessTerminated(CefRefPtr<CefBrowser> browser,
                                         TerminationStatus status) OVERRIDE;

 protected:
  jobject jhandler_;

  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(RequestHandler);
  // Include the default locking implementation.
  IMPLEMENT_LOCKING(RequestHandler);
};

#endif  // CEF_TESTS_CEFCLIENT_REQUEST_HANDLER_H_
